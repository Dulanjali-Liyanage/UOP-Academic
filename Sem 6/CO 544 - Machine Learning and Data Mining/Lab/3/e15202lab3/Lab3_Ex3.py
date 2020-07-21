#!/usr/bin/env python
# coding: utf-8

# In[32]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt 


# In[33]:


#import Boston_Housing.csv
dataset = pd.read_csv('E:/University Works/3rd Year/Semester 6/CO 544 - Machine Learning and Data Mining/Lab/3/Boston_Housing.csv',sep=',')
print(dataset.head())


# In[34]:


print ("Dataset Length: ", len(dataset)) 
print ("Dataset Shape: ", dataset.shape)


# In[35]:


#split 80% train 20% test
data_train = dataset.values[0:round(len(dataset)*0.8),0:4]
data_test = dataset.values[round(len(dataset)*0.8):,0:4]
df_train = pd.DataFrame(data_train)
df_test = pd.DataFrame(data_test)


# In[36]:


print("df_train shape = ",df_train.shape)
print("df_test shape = ",df_test.shape)


# In[37]:


#creating 50 samples (100 instances in each)
#with replacement (means not removing the row that was selected so that it is available for future selections)
def subsample(df_train):
    sampleList = list()
    while len(sampleList) < 50:
        sampleList.append(df_train.sample(n=100,replace=True))
    return sampleList


# In[38]:


sampleList = subsample(df_train)


# In[39]:


#For training samples
def createTrainXY(sample):
    xylist = list()
    X = sample.values[:,0:3]
    X = np.hstack((np.ones((100,1)),X))
    xylist.append(X)
    
    Y = sample.values[:,3]
    xylist.append(Y)
    
    return xylist


# In[40]:


#For test values
X_test = df_test.values[:,0:3]
Y_test = df_test.values[:,3]
X_test = np.hstack((np.ones((98,1)),X_test))


# In[41]:


#Determine linear regression model
def modelLR(sample):
    xylist = createTrainXY(sample)
    b_hat = np.dot(np.dot(np.linalg.inv(np.dot(xylist[0].T,xylist[0])),xylist[0].T),xylist[1])
    return b_hat


# In[42]:


#Building all the linear regression models of samples
beta_hat = list()
i = 0
while i < 50:
    b_hat = modelLR(sampleList[i])
    beta_hat.append(b_hat)
    i = i + 1


# In[43]:


#Find the response variable(y) for test data
#for each model
y_hat_X_test_list = list()
i = 0
while i < 50:
    p = np.dot(X_test,beta_hat[i])
    y_hat_X_test_list.append(p)
    i = i + 1


# In[44]:


print("y_hat_X_test_list = ",y_hat_X_test_list[0].shape)


# In[45]:


y_hat_X_test = np.zeros([98,1],dtype=float)


# In[46]:


#Simple voting
i = 0
while i < 50:
    y_hat_X_test = y_hat_X_test + y_hat_X_test_list[i]
    i = i + 1


# In[47]:


y_hat_X_test_avg = y_hat_X_test[0]/50
print("Predictions for test set = \n",y_hat_X_test_avg)


# In[48]:


#visualize residual error for test data
plt.scatter(y_hat_X_test_avg,Y_test) 
plt.xlabel("Predicted Values")
plt.ylabel("Actual Value")
plt.show()


# In[ ]:




