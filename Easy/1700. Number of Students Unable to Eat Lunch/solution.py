class Solution:
    def countStudents(self, students: list[int], sandwiches: list[int]) -> int:
        freq = [0] * 2
        for s in students:
            freq[s] += 1

        total = len(sandwiches)
        for s in sandwiches:
            if freq[s] == 0:
                break
            
            total -= 1
            freq[s] -= 1

        return total