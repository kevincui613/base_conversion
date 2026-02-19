/**
 * 十进制到二进制原码转换
 */
function decimalToBinaryOriginal(num) {
    if (num === 0) return "0";
    
    let isNegative = num < 0;
    let absNum = Math.abs(num);
    
    // 获取二进制位数
    let bits = 0;
    let temp = absNum;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    
    // 构建二进制字符串
    let binary = "";
    for (let i = bits - 1; i >= 0; i--) {
        binary += ((absNum >> i) & 1) ? "1" : "0";
    }
    
    // 添加符号位
    return (isNegative ? "1" : "0") + binary;
}

/**
 * 计算反码
 */
function binaryOnesComplement(original) {
    if (!original || original.length === 0) return original;
    
    if (original[0] === "1") {
        // 负数：除符号位外，其他位取反
        let ones = original[0];
        for (let i = 1; i < original.length; i++) {
            ones += (original[i] === "0") ? "1" : "0";
        }
        return ones;
    } else {
        // 正数：反码等于原码
        return original;
    }
}

/**
 * 计算补码
 */
function binaryTwosComplement(ones) {
    if (!ones || ones.length === 0) return ones;
    
    if (ones[0] === "1") {
        // 负数：反码加1
        let twos = ones.split("");
        let carry = 1;
        
        for (let i = twos.length - 1; i >= 1 && carry; i--) {
            if (twos[i] === "0") {
                twos[i] = "1";
                carry = 0;
            } else {
                twos[i] = "0";
            }
        }
        
        return twos.join("");
    } else {
        // 正数：补码等于原码
        return ones;
    }
}

/**
 * 十进制转十六进制
 */
function decimalToHexadecimal(num) {
    if (num === 0) return "0";
    
    let isNegative = num < 0;
    let absNum = Math.abs(num);
    
    let hex = absNum.toString(16);
    
    return (isNegative ? "-" : "") + hex;
}

/**
 * 十进制转八进制
 */
function decimalToOctal(num) {
    if (num === 0) return "0";
    
    let isNegative = num < 0;
    let absNum = Math.abs(num);
    
    let octal = absNum.toString(8);
    
    return (isNegative ? "-" : "") + octal;
}

/**
 * 主转换函数
 */
function convertDecimal(decimal) {
    // 验证输入
    decimal = parseInt(decimal, 10);
    if (isNaN(decimal)) {
        return null;
    }
    
    // 检查范围（32位有符号整数）
    if (decimal < -2147483648 || decimal > 2147483647) {
        return null;
    }
    
    let result = {
        decimal: decimal,
        binary_original: decimalToBinaryOriginal(decimal),
        binary_ones: "",
        binary_twos: "",
        hexadecimal: decimalToHexadecimal(decimal),
        octal: decimalToOctal(decimal)
    };
    
    // 计算反码和补码
    result.binary_ones = binaryOnesComplement(result.binary_original);
    result.binary_twos = binaryTwosComplement(result.binary_ones);
    
    return result;
}

/**
 * 导出转换结果为各种格式
 */
function exportResult(result, format) {
    if (!result) return "";
    
    let output = "";
    
    if (format === "text" || format === "clipboard") {
        output = `进制转换结果
========================
十进制数: ${result.decimal}

二进制表示:
  原码:  ${result.binary_original}
  反码:  ${result.binary_ones}
  补码:  ${result.binary_twos}

其他进制表示:
  十六进制: ${result.hexadecimal}
  八进制:   ${result.octal}
========================`;
    } else if (format === "json") {
        output = JSON.stringify(result, null, 2);
    } else if (format === "csv") {
        output = `类型,值\n二进制原码,${result.binary_original}\n二进制反码,${result.binary_ones}\n二进制补码,${result.binary_twos}\n十六进制,${result.hexadecimal}\n八进制,${result.octal}`;
    }
    
    return output;
}
