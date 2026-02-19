# 🚀 快速启动指南

## 最简单的方式：直接打开

在文件浏览器中找到这个文件夹，**双击 `index.html`** 即可在浏览器中打开网页版本。

---

## 如果上面的方式不起作用，试试这些：

### 选项 1：改进的浏览器支持（推荐）
```bash
# 确保你在 base_conversion 目录下
cd d:\C\base_conversion

# Python 3.x
python -m http.server 8000

# 或者用这个命令（适用于任何系统）
py -m http.server 8000

# 然后在浏览器中打开：
# http://localhost:8000/web/
```

### 选项 2：使用 Node.js
```bash
npx http-server web/
```

### 选项 3：VS Code 中打开
1. 安装 "Live Server" 扩展
2. 右键点击 `index.html`
3. 选择 "Open with Live Server"

---

## 📋 文件说明

| 文件 | 用途 |
|------|------|
| `index.html` | 主页面 - 在浏览器中打开 |
| `converter.js` | 核心转换算法 |
| `ui.js` | 用户界面交互 |
| `style.css` | 样式美化 |
| `README.md` | 完整文档 |

---

## ✨ 主要功能

✅ 十进制 → 二进制（原码、反码、补码）
✅ 十进制 → 十六进制
✅ 十进制 → 八进制
✅ 一键复制结果
✅ 导出为文本/JSON/CSV
✅ 响应式设计（支持手机/平板/电脑）
✅ 深色模式支持

---

## 🔧 技术参数

- **支持范围**: -2,147,483,648 到 2,147,483,647 (32位最大整数)
- **不需要后端服务**: 所有计算在浏览器本地进行
- **无数据上传**: 完全离线可用
- **浏览器兼容**: Chrome, Firefox, Safari, Edge (不支持 IE)

---

## 📚 与 C 版本的关系

网页版本完全实现了 C 代码的所有转换算法：

```
C版本                           网页版本
────────────────────────────

decimal_to_binary_original()  →  decimalToBinaryOriginal()
binary_ones_complement()      →  binaryOnesComplement()
binary_twos_complement()      →  binaryTwosComplement()
decimal_to_hexadecimal()      →  decimalToHexadecimal()
decimal_to_octal()            →  decimalToOctal()
convert_decimal()             →  convertDecimal()
```

**没有改动任何功能，只是用 JavaScript 重新实现了相同的逻辑**

---

## 🎓 使用示例

1. 输入 `5`，点击转换 → 查看所有进制表示
2. 尝试 `-5` → 观察二进制的原码、反码、补码区别
3. 点击快速示例按钮快速测试
4. 点击📋按钮复制单个结果
5. 使用导出功能下载结果

---

## 💬 如有问题

- 查看 `README.md` 获取详细文档
- 查看浏览器的开发者工具（F12）中的错误信息
- 确保浏览器版本足够新（2020年以后发布的版本）

---

**祝你使用愉快！** 🎉
