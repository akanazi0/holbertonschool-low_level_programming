## Raw Execution Logs

### Run 1
Naive algorithm result: 625025000
Naive algorithm time: 2.540702 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000101 seconds

### Run 2
Naive algorithm result: 625025000
Naive algorithm time: 2.620227 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000118 seconds

### Run 3
Naive algorithm result: 625025000
Naive algorithm time: 2.435564 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000098 seconds

---

## Statistical Analysis

* **Average Naive Algorithm Runtime:** 2.532164 seconds
* **Average Single-pass Algorithm Runtime:** 0.000106 seconds
* **Relative Performance Difference:** The Naive algorithm is approximately 23,888 times slower than the Single-pass algorithm.

## Sustainability Impact
The O(N^2) naive algorithm forces the CPU to execute over 1.25 billion operations for a 50,000 element array due to nested looping, whereas the O(N) single-pass algorithm accomplishes the exact same result in 50,000 operations. The dramatic runtime difference directly relates to extended CPU power consumption and lower energy efficiency at scale.
EOF