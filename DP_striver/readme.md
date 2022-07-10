# Problems on DP

- [Fibonacci nos](Fibonacci_num.cpp)
- [Climbing stairs | Count distinct sol](climbing_stairs.cpp)
- [Frog Jump | Min Energy to climb height](frog_jump.cpp)
- [House Robber | Maximum sum of non-adjacent els or Max sum of subseq](house_robber.cpp)
- [House Robber 2 | Maximum sum of non-adjacent els in CIRCULAR array](house_robber2.cpp)
- [Ninja Training | N days, 3 tasks, calc max points](ninja_training.cpp)

**DP on Grids/2D matrices**

- [Count Grid Unique Paths | all paths are unique in rec | down and right](grid_unique_paths.cpp)
- [Unique Paths II](unique_paths_two.cpp)
- [Minimum Path Sum | Each cell has a cost](min_path_sum.cpp)
- [Triangle | Fixed Starting Point and Variable Ending Point](triangle.cpp)

**DP on Subsequences/Subsets and target**

- [Subset sum equal to K | Check if problem](subset_sum_eq_to_K.cpp)
- [Count Subsets having sum == K | Positive nums](count_subset_sum_eq_to_K.cpp)
- [Partition Equal Subset Sum | Check if array can be partitioned into two equal subsets having same sum](partition_equal_subset_sum.cpp)
- [Partition Array Into Two Arrays to Minimize Sum Difference | Find min abs diff](partition_min_subset_sum_diff.cpp)
- [Count no of Partitions with given difference](partition_given_diff.cpp)
- [Target Sum | variation of prev question](target_sum.cpp)

**Classic Problems**

- [0/1 Knapsack](0_1_knapsack.cpp)
- [Coin Change I, min coins | Coin denomination and target problem](minimum_coins.cpp)
- [Coin Change II | number of combinations that make up that amount](coin_change2.cpp)
- [Unbounded Knapsack | picking an item multiple times](unbounded_knapsack.cpp)

# Notes/Ptrs

**How do you know it's a DP problem?**
- counting no of ways 
- minimum or maximum op in case of multiple ways 
- whenever concept of try all possible ways 

**Tips for developing recurrence relation**
- try to represent the problem in terms of index
- do all possible stuffs on that index according to PS
- if question says count all ways:
    - sum up all stuffs
- else if question says find min
    - take min(all stuffs)