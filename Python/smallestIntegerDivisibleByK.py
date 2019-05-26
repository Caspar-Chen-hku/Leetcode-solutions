class Solution(object):
    def smallestRepunitDivByK(self, K):
        """
        :type K: int
        :rtype: int
        """
        len_k = len(str(K))
        res = len_k
        div = '1' * (len_k)
        if int(div) < K:
            div += '1'
            res += 1
        dic_remainder = {}
        while True:
            remainder = int(div) % K
            if remainder == 0:
                return res
            elif remainder in dic_remainder:
                return -1
            dic_remainder[remainder] = 1
            sr = str(remainder)
            div = sr + '1' * (len_k - len(sr))
            res += (len_k - len(sr))
            if int(div) < K:
                div += '1'
                res += 1