from concurrent.futures import ProcessPoolExecutor
import numpy as np
import multiprocessing
import os
import sys
import time

def process_data_chunk(chunk_id):
    """Heavy mathematical calculations handled inside an array slice."""
    data = np.random.rand(10_000_000)
    result = np.exp(data) * np.sin(data)
    return np.sum(result)

if __name__ == "__main__":
    total_cores = multiprocessing.cpu_count()
    sys.stdout.write(f"System Configuration: {total_cores} Cores Detected.\n")
    
    # ----------------------------------------------------
    # PARALLEL RUN
    # ----------------------------------------------------
    sys.stdout.write("\nLaunching Parallel Workload (14 Threads)...\n")
    sys.stdout.flush()
    start_par = time.time()
    with ProcessPoolExecutor(max_workers=total_cores) as executor:
        par_results = list(executor.map(process_data_chunk, range(total_cores)))
    t_parallel = time.time() - start_par
    sys.stdout.write(f"Parallel Execution Time: {t_parallel:.4f} seconds\n")
    
    # ----------------------------------------------------
    # SEQUENTIAL RUN
    # ----------------------------------------------------
    sys.stdout.write("\nLaunching Sequential Workload (1 Core Loop)...\n")
    sys.stdout.flush()
    start_seq = time.time()
    seq_results = []
    for i in range(total_cores):
        seq_results.append(process_data_chunk(i))
    t_sequential = time.time() - start_seq
    sys.stdout.write(f"Sequential Execution Time: {t_sequential:.4f} seconds\n")
    
    # ----------------------------------------------------
    # PERFORMANCE METRICS CALCULATION
    # ----------------------------------------------------
    speedup = t_sequential / t_parallel
    efficiency = (speedup / total_cores) * 100
    
    sys.stdout.write(f"\n--- HPC PERFORMANCE METRICS ---\n")
    sys.stdout.write(f"Calculated Speedup: {speedup:.2f}x faster\n")
    sys.stdout.write(f"Core Efficiency Profile: {efficiency:.2f}%\n")
    sys.stdout.flush()