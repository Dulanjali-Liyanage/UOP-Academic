#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# In[2]:


#import Boston_Housing.csv
dataset = pd.read_csv('E:/University Works/3rd Year/Semester 6/CO 544 - Machine Learning and Data Mining/Lab/3/Boston_Housing.csv',sep=',')
print(dataset.head())


# In[3]:


print ("Dataset Length: ", len(dataset)) 
print ("Dataset Shape: ", dataset.shape)


# In[4]:


#check for missing values
print(dataset.__eq__('?').sum())


# In[5]:


#count the NaN values
print(dataset.isnull().sum())


# In[6]:


print(dataset.dtypes)


# In[7]:


#split 80% train 20% test
data_train = dataset.values[0:round(len(dataset)*0.8),0:4]
data_test = dataset.values[round(len(dataset)*0.8):,0:4]


# In[8]:


print("data_train shape = ",data_train.shape)
print("data_test shape = ",data_test.shape)


# In[22]:


X_train = data_train[:,0:3]
Y_train = data_train[:,3]
X_test = data_test[:,0:3]
Y_test = data_test[:,3]
X_train = np.hstack((np.ones((391,1)),X_train))
X_test = np.hstack((np.ones((98,1)),X_test))


# In[23]:


b_hat = np.dot(np.dot(np.linalg.inv(np.dot(X_train.T,X_train)),X_train.T),Y_train)


# In[24]:


print("beta_hat = ",b_hat)


# In[25]:


y_hat_X_train = np.dot(X_train,b_hat)
y_hat_X_test = np.dot(X_test,b_hat)


# In[26]:


print("Predictions for training set = \n",y_hat_X_train)


# In[27]:


print("Predictions for test set = \n",y_hat_X_test)


# In[28]:


plt.scatter(y_hat_X_train,Y_train,label='training')
plt.scatter(y_hat_X_test,Y_test,label='test') 
plt.xlabel("Predicted Values")
plt.ylabel("Actual Value")
plt.legend()
plt.show()


# In[ ]:




