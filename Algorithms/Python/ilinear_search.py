def search(arr, x): 
  
    for i in range(len(arr)): 
  
        if arr[i] == x: 
            return i 
  
    return -1

list = [54,26,93,17,77,31,44,55,20]
f=search(list,93)
print(f)
