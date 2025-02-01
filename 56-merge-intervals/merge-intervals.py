class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # Step 1: Sort intervals by the start value
        intervals.sort(key=lambda x: x[0])

        # Step 2: Initialize a result list
        merged = []

        # Step 3: Iterate through the sorted intervals
        for interval in intervals:
            # If merged is empty or the current interval doesn't overlap with the last one, add it
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                # If there is an overlap, merge the intervals by updating the end value
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged
