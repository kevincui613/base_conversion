/**
 * UI 交互控制
 */

/**
 * 执行转换
 */
function performConversion() {
    const input = document.getElementById("decimalInput").value.trim();
    
    if (!input) {
        showError("请输入一个十进制数");
        return;
    }
    
    const result = convertDecimal(input);
    
    if (result === null) {
        showError("输入无效或数值超出范围（-2147483648 到 2147483647）");
        return;
    }
    
    displayResult(result);
    showExportSection();
}

/**
 * 快速转换示例
 */
function quickConvert(num) {
    document.getElementById("decimalInput").value = num;
    performConversion();
}

/**
 * 显示结果
 */
function displayResult(result) {
    // 隐藏空状态和错误状态
    document.getElementById("emptyState").classList.add("hidden");
    document.getElementById("errorState").classList.add("hidden");
    
    // 显示结果容器
    const container = document.getElementById("resultContainer");
    container.classList.remove("hidden");
    
    // 填充数据
    document.getElementById("binaryOriginal").textContent = result.binary_original;
    document.getElementById("binaryOnes").textContent = result.binary_ones;
    document.getElementById("binaryTwos").textContent = result.binary_twos;
    document.getElementById("hexadecimal").textContent = result.hexadecimal;
    document.getElementById("octal").textContent = result.octal;
    
    // 显示信息
    const binary_original_len = result.binary_original.length;
    document.getElementById("resultInfo").innerHTML = 
        `✓ 转换完成 | 二进制位数：${binary_original_len} | 十进制：${result.decimal}`;
    
    // 保存当前结果供导出使用
    window.lastResult = result;
}

/**
 * 显示错误信息
 */
function showError(message) {
    document.getElementById("resultContainer").classList.add("hidden");
    document.getElementById("emptyState").classList.add("hidden");
    
    const errorState = document.getElementById("errorState");
    errorState.classList.remove("hidden");
    document.getElementById("errorMessage").textContent = "❌ " + message;
}

/**
 * 显示导出部分
 */
function showExportSection() {
    document.getElementById("exportSection").classList.remove("hidden");
}

/**
 * 复制到剪贴板
 */
function copyToClipboard(elementId, type) {
    const element = document.getElementById(elementId);
    const text = element.textContent;
    
    navigator.clipboard.writeText(text).then(() => {
        // 显示复制成功的反馈
        const btn = event.target;
        const originalText = btn.textContent;
        btn.textContent = "✓ 已复制";
        btn.classList.add("copied");
        
        setTimeout(() => {
            btn.textContent = originalText;
            btn.classList.remove("copied");
        }, 2000);
    }).catch(err => {
        console.error("复制失败:", err);
        alert("复制失败，请手动复制");
    });
}

/**
 * 导出结果
 */
function exportResult(format) {
    if (!window.lastResult) {
        alert("请先进行转换");
        return;
    }
    
    const result = window.lastResult;
    let content = "";
    let filename = `进制转换_${result.decimal}_`;
    let mimeType = "text/plain";
    
    if (format === "text") {
        content = `进制转换结果\n========================\n十进制数: ${result.decimal}\n\n二进制表示:\n  原码:  ${result.binary_original}\n  反码:  ${result.binary_ones}\n  补码:  ${result.binary_twos}\n\n其他进制表示:\n  十六进制: ${result.hexadecimal}\n  八进制:   ${result.octal}\n========================`;
        filename += `${new Date().getTime()}.txt`;
    } else if (format === "json") {
        content = JSON.stringify(result, null, 2);
        filename += `${new Date().getTime()}.json`;
        mimeType = "application/json";
    } else if (format === "csv") {
        content = `类型,值\n二进制原码,${result.binary_original}\n二进制反码,${result.binary_ones}\n二进制补码,${result.binary_twos}\n十六进制,${result.hexadecimal}\n八进制,${result.octal}`;
        filename += `${new Date().getTime()}.csv`;
        mimeType = "text/csv";
    }
    
    // 创建 Blob 并下载
    const blob = new Blob([content], { type: mimeType });
    const url = URL.createObjectURL(blob);
    const link = document.createElement("a");
    link.href = url;
    link.download = filename;
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
    URL.revokeObjectURL(url);
}

/**
 * 初始化事件监听
 */
document.addEventListener("DOMContentLoaded", function() {
    const input = document.getElementById("decimalInput");
    
    // 按 Enter 键执行转换
    input.addEventListener("keypress", function(event) {
        if (event.key === "Enter") {
            performConversion();
        }
    });
    
    // 实时反馈
    input.addEventListener("input", function() {
        if (this.value === "") {
            document.getElementById("resultContainer").classList.add("hidden");
            document.getElementById("errorState").classList.add("hidden");
            document.getElementById("emptyState").classList.remove("hidden");
        }
    });
});

// 存储最后的转换结果
window.lastResult = null;
