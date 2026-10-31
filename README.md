# C++ 实验 2026 秋季

本仓库保存 C++ 课程实验的源码、开发者测试、实验报告与验收材料。每个实验独立构建，按实验编号归档。

| 实验 | 主题 | 源码与运行说明 | 报告与验收材料 |
| --- | --- | --- | --- |
| 实验1 | 高质量编程基础：车辆执行器 Executor | [labs/lab01](labs/lab01/) | [docs/lab01](docs/lab01/) |

## 目录

```text
labs/
  lab01/                  实验1的独立 CMake 工程
    include/              对外接口
    src/                  功能实现
    tests/                GoogleTest 用例及随工程附带的框架
    script/               Windows 与 Bash 构建运行脚本
docs/
  lab01/                  实验报告、截图与验证记录
```

## 运行实验1

Windows 需要支持 C++17 的 MinGW-w64、mingw32-make 和 CMake 3.10 或以上，均需加入 `PATH`。在仓库根目录打开 PowerShell：

```powershell
.\labs\lab01\script\build_and_run.bat
```

也可以进入 [实验1工程目录](labs/lab01/) 后，按该目录的 README 运行。GoogleTest 1.12.1 已随源码保存，无需在线下载。

实验1共 22 个测试，覆盖规定的 14 个基础场景与 8 个补充场景。已通过全量测试、22 项独立运行及 100 轮乱序重复验证；整理后重新构建验收。

## 维护约定

- 新实验放入 `labs/labXX/`，对应报告和必要验收材料放入 `docs/labXX/`，并更新上方索引。
- 保留源码、构建说明和必要的测试依赖；构建产物、编辑器缓存、临时文件和重复提交压缩包由 `.gitignore` 排除。
- 第三方 GoogleTest 位于各实验的 `tests/googletest/`，保留其原许可证与说明。
- 保留测试先行的 Git 历史；最初开发提交的工程位于仓库根目录，整理提交将工程整体移入 `labs/lab01/`。
