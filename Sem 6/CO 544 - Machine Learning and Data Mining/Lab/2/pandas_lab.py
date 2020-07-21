#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd # import pandas module as pd 


# In[2]:


# create a series with a list 
s = pd.Series([1,4,-2,'home'],index=['a','b','c','d'])


# In[3]:


print(s)


# In[4]:


#Todo 1
print(s)
#according to thos datatype of s is object


# In[5]:


print(s['d'])


# In[6]:


print(s['a'])


# In[7]:


#s.astype(int) ---> cause an error
#ValueError: invalid literal for int() with base 10: 'home'



# In[8]:


print(s.astype(str))


# In[9]:


print(type(s['a']))


# In[10]:


print(type(s['d']))


# In[11]:


#so according to above results
#datatype of s cannot be chaged --- answer for the Todo 1


# In[12]:


# create a data frame with a dictionary 
data={'population':[1.5,1.2,2.0,1.4,0.8],
      'state':['Nevada','Florida','O hio','Texas','Florida'],
      'year':[2003,2000,2004,1990,1994]
     } 


# In[14]:


print("data = ",data)


# In[15]:


df=pd.DataFrame(data,index=['one','two','three','four','five'],columns= ['year','state','population','debt']) 


# In[17]:


print("df = \n",df)


# In[18]:


#4.2.2 Accessing and modifying 


# In[19]:


print(s[1:3])


# In[20]:


print(s[0])


# In[21]:


print(s['d'])


# In[22]:


print(s.values[2:])


# In[23]:


print(df[['population','state']])


# In[24]:


print(df.population) 


# In[25]:


print(df.iloc[1:])


# In[26]:


print(df.iloc[2:4:,2:5])


# In[27]:


print(df.loc['one']) 


# In[28]:


df.debt=34.67 


# In[29]:


print("df = \n",df)


# In[30]:


df.debt=[df.iloc[:,2][i]*5 for i in range(0,df.shape[0])] 


# In[31]:


print("df = \n",df)


# In[32]:


print("df = \n",df.head()) 


# In[33]:


print(df.tail(2))


# In[34]:


print(df.sample(n=3))


# In[35]:


print(df.sample(n=3))


# In[36]:


import numpy as np

df['newColomn']=pd.Series(np.random.randn(df.shape[0]),index=df.index)


# In[37]:


print("df = \n",df)


# In[38]:


print(df.drop_duplicates('state')) 


# In[39]:


print(df.state)


# In[40]:


#4.2.3 Loading data from CSV file 


# In[41]:


# without setting names 
df=pd.read_csv('sampleDataSet.csv')


# In[42]:


print("df = \n",df)


# In[43]:


# setting names
df=pd.read_csv('sampleDataSet.csv',names=['a','b','c','d','e','f','g','h','i']) 


# In[44]:


print("df = \n",df)


# In[45]:


#Todo 2
#without names take the first row of the sampleDataSet as the names of the columns
#with names it take the names as the names of each column in the sampleDataSet


# In[46]:


#4.2.4 Dealing with missing values. 


# In[47]:


print(df.isnull().g) 


# In[48]:


print(df.isnull().sum(0)) 


# In[49]:


df=df[df.isnull().a != True] 


# In[51]:


print("df = \n",df)


# In[52]:


print(df.dropna(axis=0).isnull().sum())


# In[53]:


print(df.dropna(axis=1)) 


# In[54]:


print(df.dropna(axis=1, how='all')) 


# In[55]:


print(df.dropna(axis=1, thresh=1))


# In[56]:


print(df.drop('i',axis=1))


# In[57]:


print(df.fillna(899)) 


# In[58]:


print(df.fillna(method='ffill')) 


# In[59]:


print(df.replace(6.3,600)) 


# In[60]:


print(df.replace('.',np.nan)) 


# In[61]:


#df[np.random.rand(df.shape[0]>0.5)]=1.5  ----> cause an error
#TypeError: an integer is required



# In[62]:


#4.2.5 Applying functions 

f=lambda df: df.max()-df.min() 


# In[64]:


print("applying function element wise =\n",df.iloc[: ,3:5].apply(f)) # applying function element wise 


# In[65]:


def sf(x):
    return x.max()-x.min() 


# In[66]:


print(df.iloc[: ,3:5].apply(sf)) # applying function element wise 


# In[67]:


#4.2.6 Group Operations


# In[68]:


grouped=df[['a','b','e']].groupby(df['i']) #group according to column ‘i’ 


# In[69]:


print(grouped.mean()) 


# In[70]:


grouped=df[['a','b','e']].groupby([df['i'],df['c']]).mean() 


# In[71]:


print(grouped.unstack()) 


# In[72]:


#4.2.7 Data Summarizing 


# In[73]:


print(df['a'].nunique()) # number of distinct values in a column


# In[74]:


print(df['a'].value_counts()) # count the number of rows for each unique value


# In[75]:


print(df.describe()) # descriptive statistics for each column 


# In[76]:


print(df.mean()) 


# In[77]:


print(df.sort_index().head())


# In[78]:


#4.2.8 Data Visualization 


# In[82]:


import matplotlib.pyplot as plt

df.plot(kind='hist')
plt.show()


# In[83]:


df.plot(kind='bar')
plt.show()


# In[84]:


df.boxplot()
plt.show()


# In[85]:


#4.3 Try Out 


# In[86]:


#1
df=pd.read_csv('lab02Exercise01.csv',names=['Chanel1','Chanel2','Chanel3','Chanel4','Chanel5']) 


# In[87]:


print("df = \n",df)


# In[88]:


#2


# In[89]:


print(df.isnull())


# In[90]:


print(df.mean())


# In[91]:


print(df.fillna(df.mean()))


# In[93]:


ndf = df.fillna(df.mean())


# In[94]:


print("ndf = \n",ndf)


# In[96]:


#3
from pandas.plotting import scatter_matrix 
scatter_matrix (ndf , alpha =0.2 , figsize =(6, 6))
plt.show()


# In[97]:


from pandas.plotting import scatter_matrix 
scatter_matrix (ndf , alpha =0.2 , figsize =(6, 6),diagonal='kde')
plt.show()


# In[98]:


#4


# In[99]:


#create a new column with some random values
ndf['class']=pd.Series(np.random.randn(ndf.shape[0]),index=ndf.index)


# In[100]:


print("ndf = \n",ndf)


# In[101]:


#logic to fill the new class

newclass = []
i = 0
while i < len(ndf):
    if (ndf.values[i,0]+ndf.values[i,4])/2 < (ndf.values[i,1]+ndf.values[i,2]+ndf.values[i,3])/3:
        newclass.append(1)
    else:
        newclass.append(0)
    i = i + 1


# In[102]:


ndf['class'] = newclass


# In[103]:


#fill the 'class' column with necessary conditions applied
print(ndf)


# In[ ]:





# In[ ]:





# In[ ]:




