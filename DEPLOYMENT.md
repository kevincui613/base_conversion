# 🚀 部署到 GitHub Pages 完整指南

## 📋 部署步骤

### 第一步：创建 GitHub 仓库

1. 访问 https://github.com/new
2. 填写仓库信息：
   - **Repository name**: `base_conversion`（可自定义）
   - **Description**: `进制转换工具 - Web 版本`（可选）
   - **Public** 📢（必须，这样别人才能访问）
3. **不要** 勾选 "Initialize this repository with:"
4. 点击 **Create repository**

### 第二步：连接本地仓库到 GitHub

在项目目录的 PowerShell 中运行：

```powershell
# 添加远程仓库（替换 kevincui613 为你的实际用户名）
git remote add origin https://github.com/kevincui613/base_conversion.git

# 重命名 master 分支为 main（GitHub 推荐）
git branch -M main

# 推送代码到 GitHub
git push -u origin main
```

**之后，你的代码就在 GitHub 上了！** ✅

### 第三步：启用 GitHub Pages 

这是让别人访问你网站的关键一步：

1. 在 GitHub 上打开你的仓库
2. 点击 **Settings** （齿轮图标）
3. 在左侧菜单中找到 **Pages**
4. 在 **Source** 中选择：
   - **Branch**: `main`
   - **Folder**: `/root`（不是 `/docs`）
5. 点击 **Save**

### 第四步：等待部署完成

1-2 分钟后，你会看到：
```
✓ Your site is published at https://kevincui613.github.io/base_conversion/
```

**这就是你的网站链接！可以分享给别人了！** 🎉

---

## 📝 访问 URL

你的网站地址是：
```
https://kevincui613.github.io/base_conversion/web/
```

或者如果你想要根目录就能访问，可以将 `web` 文件夹中的文件移到根目录。

---

## ⚙️ 后续更新网站

当你对网站进行修改时，只需：

```powershell
# 1. 提交本地更改
git add .
git commit -m "更新说明"

# 2. 推送到 GitHub
git push origin main
```

1-2 分钟后，网站会自动更新。

---

## 🆘 常见问题

### Q: 没看到部署完成信息怎么办？
A: 等待 2-5 分钟后刷新页面。检查 Settings → Pages 中的部署状态。

### Q: 404 Not Found（页面不存在）
A: 
- 确保 GitHub Pages 已启用
- 确认 URL 是否正确（注意大小写）
- 检查文件是否真的推送上去了（在 GitHub 网页上查看）

### Q: 如何修改网站标题和描述？
A: 编辑 `web/index.html`，修改 `<title>` 标签，然后 `git push` 更新。

### Q: 可以用自己的域名吗？
A: 可以。在 Settings → Pages → Custom domain 中设置。但这需要额外的域名设置。

---

## 📊 部署流程图

```
你的本地代码
    ↓
git add & commit
    ↓
git push 到 GitHub
    ↓
GitHub Actions 自动部署
    ↓
GitHub Pages 生成链接
    ↓
别人访问你的网站
```

---

## 🔐 隐私和权限

- **Public**：所有人都可以看到代码和网站 (推荐)
- **Private**：只有你能看到代码，但网站链接需要单独分享

对于这个项目，**Public** 是最好的选择。

---

## 🎯 下一步

✅ 完成上述步骤后，你可以：
- 分享网站链接给朋友
- 修改网站内容并自动更新
- 将 GitHub 链接放在简历或个人网站上
- 邀请他人贡献代码

---

**需要帮助？** 检查 GitHub Actions 标签页查看部署日志。

---

**更新时间**: 2026年2月19日
