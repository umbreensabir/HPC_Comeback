from concurrent.futures import ProcessPoolExecutor
import multiprocessing
import os
import sys

def worker_task(core_number):
    """This function executes in parallel across your logical cores."""
    # We use write and flush to completely force the terminal to print instantly
    sys.stdout.write(f"Hello World from CPU thread core loop: {core_number} (PID: {os.getpid()})\n")
    sys.stdout.flush()

if __name__ == "__main__":
    total_cores = multiprocessing.cpu_count()
    
    sys.stdout.write(f"Master process started. Spawning workers across {total_cores} cores...\n\n")
    sys.stdout.flush()
    
    # ProcessPoolExecutor automatically handles worker initialization on Ubuntu
    with ProcessPoolExecutor(max_workers=total_cores) as executor:
        # Map your core identifiers across the system threads
        executor.map(worker_task, range(total_cores))
        
    sys.stdout.write("\nAll parallel processes completed successfully.\n")
    sys.stdout.flush()
