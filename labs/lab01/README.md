# 实验1 高质量编程基础

本目录是独立的 CMake 工程。返回[仓库首页](../../README.md)，或查看[实验报告与验收材料](../../docs/lab01/)。

实现 `adas::Executor`，支持默认或指定初始位姿、前进 `M`、左转 `L`、右转 `R`、连续指令和状态查询。接口与课件一致，坐标为 `std::int32_t`。按实验约束，调用者保证输入合法，且整个执行过程中坐标不溢出。

## 构建运行

Windows 环境需要 CMake 3.10 或以上、支持 C++17 的 MinGW-w64，以及 `mingw32-make`，均需加入 PATH。在工程根目录的命令提示符中执行：

```bat
script\build_and_run.bat
```

在 PowerShell 中执行：

```powershell
.\script\build_and_run.bat
```

GoogleTest 1.12.1 已随工程保存在 `tests/googletest`，不需要在线下载。构建目录 `build` 会在首次运行时生成。

## 验证

共 22 个测试，包括要求的 14 个基础场景和 8 个补充场景。每个用例创建自己的执行器，并断言完整的 x、y、heading。

```bat
script\run.bat --gtest_shuffle --gtest_repeat=100 --gtest_random_seed=2026
script\run.bat --gtest_filter=ExecutorTest.should_move_one_grid_when_facing_E
ctest --test-dir build --output-on-failure
git log --oneline
```

已验证：22/22 用例通过；随机顺序重复 100 轮全部通过；22 个用例逐一在独立进程运行通过。CTest 将整个 GoogleTest 可执行程序注册为 1 项测试，程序内部包含 22 个用例。

工厂返回的原始指针由调用者负责释放，建议用 `std::unique_ptr<adas::Executor>` 接管；内存分配失败时返回 `nullptr`。查询接口为 `const noexcept`，不会改变状态。

Git 历史保留起始工程、构建修正、初始化测试与实现、前进测试与实现、转向测试与实现及补充测试，测试提交包含可编译的接口桩。仓库中的报告和截图位于 [docs/lab01](../../docs/lab01/)。报告内的 `cpp-training` 指独立提交包中的工程名，对应本仓库的 `labs/lab01`。

Linux/macOS 可在本目录执行 `bash script/build_and_run.sh`。清理已构建目标时，在本目录执行 `script\clean.bat` 或 `bash script/clean.sh`；清理脚本通过自身位置定位工程，不依赖调用时的工作目录。

若 CMake 对 GoogleTest 的最低兼容版本显示弃用提示，该提示来自原附带测试框架；本次构建与测试均通过。
