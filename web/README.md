# 进制转换工具 - 网页版本

## 📌 概述

这是原 C 项目的网页版本实现，提供了一个现代化的 Web 界面，用于十进制数的进制转换。

## ✨ 功能特性

### 核心转换功能
- **二进制原码** (Sign-Magnitude Representation)
- **二进制反码** (Ones' Complement)
- **二进制补码** (Two's Complement)
- **十六进制** (Hexadecimal)
- **八进制** (Octal)

### 用户界面特点
- 🎨 现代化、响应式设计
- 📱 支持桌面、平板、手机多种设备
- 🌙 支持深色模式
- ⚡ 实时转换反馈
- 📋 一键复制结果
- 📥 支持下载导出（文本、JSON、CSV 格式）
- 📚 内置教学说明

## 📁 文件结构

```
web/
├── index.html        # 主 HTML 页面
├── converter.js      # 核心转换逻辑
├── ui.js            # UI 交互控制
├── style.css        # 样式表
└── README.md        # 本文件
```

## 🚀 使用方法

### 方法 1：直接打开文件（最简单）
1. 在文件浏览器中打开 `index.html`
2. 或在浏览器地址栏中拖拽 `index.html` 文件

### 方法 2：使用 Python 本地服务器

```bash
# Python 3.x
python -m http.server 8000
# 或
py -m http.server 8000

# 然后在浏览器中访问: http://localhost:8000/web/
```

### 方法 3：使用 Node.js 本地服务器

```bash
# 使用 http-server
npx http-server web/

# 使用 Live Server 扩展 (VS Code)
# 在 VS Code 中右键点击 index.html，选择 "Open with Live Server"
```

## 📖 使用指南

### 基本操作
1. 在输入框中输入一个十进制数（-2147483648 到 2147483647）
2. 点击"转换"按钮或按 Enter 键
3. 查看下方的转换结果

### 快速示例
使用预设的示例按钮快速测试：
- **5** - 正数示例
- **-5** - 负数示例  
- **127** - N位整数边界值
- **-128** - 负数边界值
- **0** - 零值

### 复制结果
点击每个结果框右侧的📋按钮可一键复制到剪贴板

### 导出结果
支持三种导出格式：
- **文本** - 易读的文本格式
- **JSON** - 结构化数据格式
- **CSV** - 表格数据格式

## 🔄 与 C 版本的对应关系

| 功能 | C 文件 | 网页版本 |
|------|--------|---------|
| 二进制原码 | `decimal_to_binary_original()` | `converter.js` |
| 二进制反码 | `binary_ones_complement()` | `converter.js` |
| 二进制补码 | `binary_twos_complement()` | `converter.js` |
| 十六进制 | `decimal_to_hexadecimal()` | `converter.js` |
| 八进制 | `decimal_to_octal()` | `converter.js` |
| 结果显示 | `print_conversion_result()` | `ui.js` |
| 验证和错误处理 | `convert_decimal()` | `converter.js` & `ui.js` |

## 🎓 转换原理

### 原码 (Sign-Magnitude)
- 第一位表示符号（0=正，1=负）
- 其余位表示数值的绝对值
- 例：-5 → 符号位(1) + |5|的二进制(101) → 11000101

### 反码 (Ones' Complement)
- 正数的反码 = 原码
- 负数的反码 = 原码取反（符号位不变）
- 例：-5的原码 11000101 → 反码 10111010

### 补码 (Two's Complement)
- 正数的补码 = 原码
- 负数的补码 = 反码 + 1
- 补码是计算机中整数的标准表示
- 例：-5的反码 10111010 + 1 → 补码 10111011

### 十六进制 & 八进制
- 用于简化二进制表示
- 十六进制：0-9, A-F (基数16)
- 八进制：0-7 (基数8)

## 🌐 浏览器兼容性

| 浏览器 | 版本 | 支持 |
|--------|------|------|
| Chrome | 60+ | ✅ |
| Firefox | 55+ | ✅ |
| Safari | 12+ | ✅ |
| Edge | 79+ | ✅ |
| IE 11 | - | ❌ |

## 🛠️ 开发和修改

### 项目架构
```
输入验证
    ↓
核心转换逻辑 (converter.js)
    ├─ decimalToBinaryOriginal()
    ├─ binaryOnesComplement()
    ├─ binaryTwosComplement()
    ├─ decimalToHexadecimal()
    └─ decimalToOctal()
    ↓
结果显示 (ui.js)
    ├─ displayResult()
    ├─ copyToClipboard()
    └─ exportResult()
    ↓
样式渲染 (style.css)
```

### 如何修改样式
编辑 `style.css` 中的 CSS 变量：
```css
:root {
    --primary-color: #2563eb;      /* 主色调 */
    --success-color: #10b981;      /* 成功色 */
    --error-color: #ef4444;        /* 错误色 */
    /* ... 更多变量 */
}
```

### 如何添加新的转换格式
1. 在 `converter.js` 中添加新的转换函数
2. 在 `convertDecimal()` 中调用新函数
3. 在 `index.html` 中添加新的结果显示区域
4. 在 `ui.js` 中的 `displayResult()` 中填充结果

## 📊 性能指标

- 页面加载时间: < 100ms
- 转换响应时间: < 10ms
- 支持范围: 32位有符号整数 (-2,147,483,648 到 2,147,483,647)

## 🔒 数据安全

- 所有计算在浏览器本地进行
- 不上传任何数据到服务器
- 无跟踪或数据收集

## 📝 更新日志

### v1.0.0
- ✅ 基本功能实现
- ✅ 响应式设计
- ✅ 导出功能
- ✅ 深色模式支持
- ✅ 教学说明
- ✅ 快速示例

## 🤝 贡献指南

欢迎提交 Issue 和 Pull Request！

## 📄 许可证

本项目采用与原 C 项目相同的许可证。

## 🔗 相关链接

- [原 C 项目](../README.md)
- [项目架构说明](../ARCHITECTURE.md)
- [二进制表示相关资料](https://en.wikipedia.org/wiki/Two%27s_complement)

## ❓ 常见问题

### Q: 为什么我输入的数字没有立即显示结果？
A: 请确保输入是有效的十进制数，或点击"转换"按钮执行转换。你也可以按 Enter 键快速转换。

### Q: 数值范围限制是什么？
A: 支持 32 位有符号整数范围：-2,147,483,648 到 2,147,483,647

### Q: 支持小数吗？
A: 不支持。该工具只支持整数转换。如需小数支持，请修改转换算法。

### Q: 可以离线使用吗？
A: 可以。将整个 `web/` 文件夹下载到本地，直接打开 `index.html` 即可离线使用。

### Q: 如何在我的网站上集成这个工具？
A: 可以将 `converter.js` 作为独立模块引入，通过 `convertDecimal()` 函数调用核心功能。

## 👨‍💻 开发者信息

基于原 C 项目的核心算法，使用现代 Web 技术实现。

---

**最后更新**: 2026年2月19日
