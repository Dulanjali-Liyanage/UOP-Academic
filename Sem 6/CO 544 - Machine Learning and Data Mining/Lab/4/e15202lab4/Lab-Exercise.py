#!/usr/bin/env python
# coding: utf-8

# In[78]:


#Importing Matplotlib
import matplotlib
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d #importing modules for 3D plotting


# In[79]:


from sklearn import datasets #import standard data sets 
wine_dataset =datasets.load_wine()


# In[80]:


from sklearn.decomposition import PCA


# In[81]:


wine_data = wine_dataset["data"] #defining features values 
wine_labels = wine_dataset["target"] #defining target variable values


# In[82]:


print("data shape = ",wine_data.shape)


# In[83]:


print("target shape = ",wine_labels.shape)


# In[84]:


import numpy as np


# In[85]:


labels = np.reshape(wine_labels,(178,1))


# In[86]:


final_wine_data = np.concatenate([wine_data,labels],axis=1)


# In[87]:


final_wine_data.shape


# In[88]:


import pandas as pd


# In[89]:


final_wine_dataset = pd.DataFrame(final_wine_data)


# In[90]:


print(final_wine_dataset)


# In[91]:


features = wine_dataset.feature_names


# In[92]:


print("features = \n",features)


# In[93]:


features_labels = np.append(features,'label')


# In[94]:


final_wine_dataset.columns = features_labels


# In[95]:


print(final_wine_dataset)


# In[96]:


print("Unique values of label = ",final_wine_dataset['label'].unique())


# In[97]:


print("Dataset datatypes =\n",final_wine_dataset.dtypes)


# In[98]:


from sklearn.preprocessing import StandardScaler
x = final_wine_dataset.loc[:, features].values
x = StandardScaler().fit_transform(x) # normalizing the features


# In[99]:


print("Feature shape = ",x.shape)


# In[100]:


#print mean and standard deviation of normalized data
print("mean = ",np.mean(x))
print("standard deviation = ",np.std(x))


# In[101]:


feat_cols = ['feature'+str(i) for i in range(x.shape[1])]


# In[102]:


normalised_wine = pd.DataFrame(x,columns=feat_cols)


# In[103]:


print(normalised_wine)


# In[104]:


#PCA analysis
pca_wine = PCA(n_components=3)


# In[105]:


principalComponents_wine = pca_wine.fit_transform(x)


# In[106]:


principal_wine_Df = pd.DataFrame(data = principalComponents_wine, columns = ['principal component 1', 'principal component 2','principal component 3'])


# In[107]:


#3 principal components
print("data frame with principal components = \n",principal_wine_Df)


# In[108]:


print('Explained variation per principal component: {}'.format(pca_wine.explained_variance_ratio_))


# In[109]:


#Visualize PCA in 3D

fig = plt.figure(figsize=(10,10))
ax = fig.add_subplot(111, projection='3d') #creating 3D subplot
ax.set_xlabel('Principal Component - 1')
ax.set_ylabel('Principal Component - 2')
ax.set_zlabel('Principal Component - 3')
ax.set_title("Principal Component Analysis of Wine Dataset")
targets = [0,1,2]
colors = ['r', 'g','b']
for target, color in zip(targets,colors):
    indicesToKeep = final_wine_dataset['label'] == target
    ax.scatter(principal_wine_Df.loc[indicesToKeep, 'principal component 1']
               , principal_wine_Df.loc[indicesToKeep, 'principal component 2']
                , principal_wine_Df.loc[indicesToKeep, 'principal component 3'],c = color,marker='o',s=50)

ax.legend(targets)
plt.show()


# In[ ]:




