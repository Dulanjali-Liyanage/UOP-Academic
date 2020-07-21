#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.pyplot as plt


# In[2]:


x= np.array([1,2,3,4,5,6,7,8,9,10]) #array of independent variable values 
y= np.array([2,5,7,8,9,11,14,15,17,19]) #array of dependent variable values


# In[3]:


n = np.size(x) #get the number of observations


# In[4]:


#determining the mean values of variables
m_x=np.mean(x) 
m_y=np.mean(y)


# In[6]:


#to find b_1 estimator value
SS_xy = np.sum(y*x) - n*m_y*m_x 
SS_xx = np.sum(x*x) - n*m_x*m_x


# In[7]:


#determining the parameter values 
b_1 = SS_xy / SS_xx 
b_0 = m_y - b_1*m_x


# In[13]:


plt.scatter(x, y,color = "b", marker = "*", s = 60) #plotting a scatter plot 
plt.title("Simple Linear Regression") #adding a title to the graph 
plt.xlabel("Independent Variable") #adding axis labels 
plt.ylabel("Dependent Variable")
plt.show()


# In[14]:


y_pred = b_0 + b_1*x #predicting response variable values 
plt.plot(x, y_pred, color = "r") #plotting the predicted line 
plt.show() #displaying the plot


# In[ ]:




