#This is the maximum kinds of chars that can appear in the string
NO_OF_CHARS = 95

class Solution:
    
    def lengthOfLongestSubstring(self, string: str) -> int:
        if string=="":
            return 0
        n = len(string) 
        cur_len = 1        # To store the lenght of current substring 
        max_len = 1        # To store the result 
        prev_index = 0    # To store the previous index 
        i = 0
        
        # Initialize the visited array as -1, indicating 
        # that character has not been visited yet. 
        visited = [-1] * NO_OF_CHARS 
        
        # Mark first character as visited by storing the index 0
        # Assume all the characters have ascii code greater than 40
        visited[ord(string[0])-40] = 0
        
        for i in range(1,n): 
            prev_index = visited[ord(string[i])-40] 
        
            # If the currentt character is not present in the already 
            # processed substring or it is not part of the current NRCS, 
            # then do cur_len++ 
            if prev_index == -1 or (i - cur_len > prev_index): 
                cur_len+=1
            
            # If the current character is present in currently considered 
            # NRCS, then update NRCS to start from the next character of 
            # previous instance. 
            else: 
                # check whether length of the previous NRCS was greater 
                # than max_len or not. 
                if cur_len > max_len: 
                    max_len = cur_len 
            
                cur_len = i - prev_index 
            
            # update the index of current character 
            visited[ord(string[i])-40] = i 
             
        # Compare the length of last NRCS with max_len and update if needed
        if cur_len > max_len: 
            max_len = cur_len 
        
        return max_len         
