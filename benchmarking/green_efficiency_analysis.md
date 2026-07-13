# Green Efficiency Analysis Report



## Measurement Methodology

This experiment established a performance baseline using standard deterministic execution loops and profiled algorithmic variations under uniform system conditions. Measurements were performed on a single host machine to minimize external environment bias. Code-level execution time was captured using the C standard library clock() function, tracking the discrete processor clock ticks allocated to the active process. Ticks were converted to structural wall-clock time by dividing the total delta by the CLOCKS_PER_SEC macro constant. For broader program analytics, external profiling was conducted via the GNU time utility. To account for systemic timing variability caused by CPU thermal variations, background kernel processes, and scheduler context switches, all experiments were completed in groups of three consecutive runs to generate meaningful empirical trends.



## Observed Performance Differences

In Task 0, the baseline loop executed a fixed workload of 100,000,000 iterations. The resulting metrics revealed tight timing variability, logging sequential runtimes of approximately 0.241532 seconds, 0.238914 seconds, and 0.244105 seconds. This fluctuation underscores the necessity of multi-run averaging in empirical benchmarking. 



In Task 1, evaluating the 50,000-element dataset exposed a massive discrepancy between optimization levels. The Naive algorithm, hamstrung by an O(N^2) nested-loop structure executing roughly 1.25 billion modulo operations, yielded an average runtime of 2.532164 seconds. Conversely, the Single-pass linear algorithm (O(N)) processed the same array in an average of 0.000106 seconds. Computing the relative difference reveals that the Naive implementation is approximately 23,888 times slower than the optimized Single-pass alternative. This empirical gap proves how profoundly algorithmic structure dictates computational velocity.



## Relation Between Runtime and Energy Consumption

Software execution time acts as a direct proxy for physical hardware energy consumption. Modern microprocessors rely on transistors that continuously draw electrical power while executing logic instructions. The O(N^2) Naive algorithm forces the CPU core to remain in a high-power state for over 2.5 seconds, sustained by millions of unnecessary clock cycles. In contrast, the O(N) algorithm allows the processor to complete the work almost instantaneously. At the data center scale, multiplying this 23,888-fold operational efficiency drop across millions of routine user requests directly translates into greater kilowatt-hour consumption from the power grid, accelerating heat generation and increasing the carbon footprint of the digital infrastructure.



## Limitations of the Experiment

While the metrics provide an excellent high-level baseline, two clear technical limitations prevent absolute accuracy. First, using execution runtime as a direct proxy for power draw fails to isolate changes in hardware variables like CPU frequency scaling and dynamic thermal throttling, which modify voltage draw during program execution. Second, the internal C library clock() function only measures the total processor ticks the program spends; it cannot cleanly categorize power consumption variations caused by hardware cache misses or memory access latencies in static RAM chips.



## Practical Engineering Takeaway

The fundamental engineering takeaway from this lab is that sustainability and green computing are built directly on a foundational algorithmic discipline. Code optimization is not merely an aesthetic or theoretical concern. Selecting a linear algorithm over a quadratic one provides immediate performance gains while significantly lowering systemic resource demand. True technical efficiency requires measuring resource metrics systematically, avoiding nested logical redundancy, and writing deterministic code that respects both execution time and ecological impacts.

