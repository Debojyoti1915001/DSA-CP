class Solution:

    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:

        @cache

        def dp(i, prev, prev_cnt, k):

            # set it to inf as we will take the min later

            if k < 0: return inf

            # we delete all characters, return 0

            if i == len(s): return 0

            # here we can have two choices, we either

            # 1. delete the current char

            # 2. keep the current char

            # we calculate both result and take the min one

            delete = dp(i + 1, prev, prev_cnt, k - 1)

            if s[i] == prev:

                # e.g. a2 -> a3

                keep = dp(i + 1, prev, prev_cnt + 1, k)

                # add an extra 1 for the following cases

                # since the length of RLE will be changed

                # e.g. prev_cnt = 1: a -> a2

                # e.g. prev_cnt = 9: a9 -> a10

                # e.g. prev_cnt = 99: a99 -> a100 

                # otherwise the length of RLE will not be changed

                # e.g. prev_cnt = 3: a3 -> a4

                # e.g. prev_cnt = 8: a8 -> a9

                # alternative you can calculate `RLE(prev_cnt + 1) - RLE(cnt)`

                if prev_cnt in [1, 9, 99]:

                    keep += 1

            else:

                # e.g. a

                keep = dp(i + 1, s[i], 1, k) + 1

            return min(delete, keep)

        

        # dp(i, prev, prev_cnt, k) returns the length of RLE with k characters to be deleted

        # starting from index i 

        # with previous character `prev`

        # with `prev_cnt` times repeated so far

        return dp(0, "", 0, k)
        