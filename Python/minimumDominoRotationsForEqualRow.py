class Solution(object):
    def minDominoRotations(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        rotA = [0, 0, 0, 0, 0, 0]
        rotB = [0, 0, 0, 0, 0, 0]

        for i in range(1, 7):
            for j in range(0, len(A)):
                if A[j] == i:
                    continue
                elif B[j] == i:
                    rotA[i-1] += 1
                    continue
                else:
                    rotA[i-1] = 1e9
                    break
            
        for i in range(1, 7):
            for j in range(0, len(B)):
                if B[j] == i:
                    continue
                elif A[j] == i:
                    rotB[i-1] += 1
                    continue
                else:
                    rotB[i-1] = 1e9
                    break
                    
        if rotA.count(1e9) == 6 and rotB.count(1e9) == 6:
            return -1
        else:
            return min(min(rotA), min(rotB))