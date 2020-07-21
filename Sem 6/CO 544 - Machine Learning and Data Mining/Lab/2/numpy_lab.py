#!/usr/bin/env python
# coding: utf-8

# In[51]:


import numpy as np  # import numpy module as np


# In[52]:


a=np.array([1,2,3]) # Creating 1D array


# In[53]:


print("Data type of a = ",a.dtype)  # return the data type of the array


# In[54]:


print("a = ",a)


# In[55]:


matrix = np.array ([np.arange (3), [i for i in range(1 ,4)],[6 ,7 ,8]])
print("matrix = ",matrix)


# In[56]:


#2.2 Initialization


# In[57]:


print("array of all zero of float data type = ",np.zeros((5,2,2),dtype=float)) # array of all zero of float data type


# In[58]:


#np.ones(4,5) # array full of one’s --->Cause an error
#TypeError: data type not understood



# In[59]:


print("array full of one’s = ",np.ones((4,5),dtype=int)) # array full of one’s


# In[60]:


print("array which initial content is random = ",np.empty([3,4])) #array which initial content is random 


# In[61]:


print("array with evenly spaced values = ",np.arange (2 ,10 ,2)) # array with evenly spaced values 


# In[62]:


print("array with evenly spaced values = ",np.arange (2 ,10 ,1)) # array with evenly spaced values 


# In[63]:


print("rearranging the size of the array = ",np.arange (2 ,10 ,1).reshape(4,2)) #rearranging the size of the array 


# In[64]:


print("creates an array with constant values = ",np.full ([2 ,3] , 4)) # creates an array with constant values 


# In[65]:


print("creates an identity matrix = ",np.eye(3)) # creates an identity matrix


# In[66]:


print("creates an evenly spaced array within specified interval = ",np.linspace (2 ,3,5)) # creates an evenly spaced array within specified interval


# In[67]:


#2.3 Copying, Sorting, Slicing 


# In[68]:


nt = np.copy(matrix) #returns the copy of the object
print("nt =\n",nt)


# In[69]:


st = matrix.copy() #deep copy
print("st = \n",st)


# In[70]:


print("\noriginal matrix = \n",matrix)


# In[71]:


matrix[0,2] = 5
print("\nchanged original matrix = \n",matrix)


# In[72]:


print("\nafter matrix chnage \n st = \n",st)
#st copy has changed to the new values of the matrix


# In[73]:


print("\nafter matrix chnage \n nt = \n",nt)
#nt has not chnaged to the new values of the matrix


# In[74]:


#again change the matrix to the original values
matrix[0,2] = 2
print("original matrix = \n",matrix)


# In[75]:


rt = matrix.view() #shallow copy
print("rt = \n",rt)


# In[76]:


matrix[0,2] = 10
print("\nchanged original matrix = \n",matrix)


# In[77]:


print("\nafter matrix chnage \n rt = \n",rt)
#rt copy has changed to the new values of the matrix


# In[78]:


#change the matrix
matrix[0,0] = 20
print("changed original matrix = \n",matrix)


# In[79]:


matrix.sort() # sorts in ascending order 
print("changed original matrix = \n",matrix)


# In[80]:


#change the matrix
matrix[0,0] = 30
print("changed original matrix = \n",matrix)


# In[81]:


matrix.sort(axis=1) #sort along the specified axis 
print("changed original matrix = \n",matrix)


# In[82]:


#again change the matrix to the original values
matrix[0,0] = 0
matrix[0,1] = 1
matrix[0,2] = 2
print("original matrix = \n",matrix)


# In[83]:


print(matrix [0: ,:1]) # 2D array slicing 


# In[84]:


print(matrix [:2, 0:2])


# In[85]:


print(matrix [:1, :])


# In[86]:


#2.3.1 Try out 


# In[87]:


print(matrix [1,0])


# In[88]:


matrix [0] = 42 


# In[89]:


print("matrix = ",matrix)


# In[90]:


print(matrix [1:3])


# In[91]:


#matrix [] ---> cause an error
#SyntaxError: invalid syntax



# In[92]:


print(matrix [1:])


# In[93]:


print(matrix [1:100])


# In[94]:


print(matrix [:])


# In[95]:


print(matrix [1: ,:2])


# In[96]:


print(matrix [:2, 1:])


# In[97]:


print(matrix.ravel ())


# In[98]:


print(matrix [: ,1]. copy ())


# In[99]:


print(matrix [1]. tolist ()) 


# In[100]:


#matrix.reshape(−1) ---> cause an error
#SyntaxError: invalid character in identifier



# In[101]:


print("matrix = ",matrix)


# In[102]:


print(matrix.reshape(9,order='F'))


# In[103]:


#2.4.1 Try out 


# In[104]:


print(np.sqrt(matrix)) 


# In[105]:


print(np.exp(matrix)) 


# In[106]:


print(np.min(matrix))


# In[107]:


print(np.max(matrix, axis=1))


# In[108]:


print(np.min(np.maximum(np.random.randn(4),np.random.randn(4))))


# In[109]:


print(np.mean(matrix))


# In[110]:


print(np.mean(matrix, axis=0))


# In[111]:


print(np.sum(matrix))


# In[112]:


print(np.invert(matrix))


# In[113]:


print(np.random.randn(5))


# In[114]:


print(np.trace(matrix))


# In[115]:


#implement Random Walk

import random

def randomWalk(startPosition):
    walked_path = np.zeros(500)
    count = 0
    
    for i in range(startPosition,500):
        test = random.random()
        #+1 and -1 has equal probability
        if test >= 0.5:
            count = count + 1
        else:
            count = count - 1
    
        walked_path[i] = count
    
    return walked_path


# In[116]:


#plot the random walk
import matplotlib.pyplot as plt

steps = np.arange(500)

plt.figure()
plt.xlabel('Steps')
plt.ylabel('Random Walk Position')

plt.plot(steps,randomWalk(10))
plt.show()





