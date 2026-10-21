# High Performance Computing: Multi-Core Scalability & Array Vectorization

An exploration of multi-core parallel computing paradigms, performance benchmarking, and hardware scaling boundaries utilizing native Linux systems architectures.

## 💻 System Configuration & Test Bed
* **Operating System:** Ubuntu 24.04 LTS (Linux Native Kernel)
* **Compute Infrastructure:** 16-Core Logical Processor Architecture (ThinkPad T14 Hardware Array)
* **Primary Toolchain:** C++ (GCC Compiler Toolchain, OpenMP Parallel Framework), Python (Virtual Environment Sandbox, NumPy Matrix Calculation Vector Engine)

## 📊 Benchmarks: Parallel Array Vectorization

This phase evaluates multi-core processing efficiency by crunching through element-wise mathematical calculations (trigonometric and exponential processing) across **140 million complex floating-point numbers simultaneously** using Python's `ProcessPoolExecutor` and unbuffered system streams.

### Performance Scaling Profile
* **Sequential Baseline Execution (Single-Core Loop):** `10.0495 seconds`
* **Parallel Execution (14 Threads Active):** `3.0508 seconds`
* **Calculated Speedup Ratio:** `3.29x faster`
* **Core Efficiency Tracking:** `20.59%`

### Hardware Bottleneck Diagnostics
While processing acceleration achieved a **3.29x speedup**, the scaling profile reveals classic memory bus saturation hurdles (*The Memory Wall*). Generating massive numerical vector sets simultaneously fully saturates the local RAM bandwidth, causing individual CPU worker threads to encounter memory latency pauses while retrieving system matrices into L3 caches.

## 🚀 Repository Blueprint
* `/cpp_parallel`: Multi-threaded task distribution environments managed via compiled native binary loops and OpenMP frameworks.
* `/python_parallel`: Isolated multi-process calculations sandbox utilizing vector optimization tools.