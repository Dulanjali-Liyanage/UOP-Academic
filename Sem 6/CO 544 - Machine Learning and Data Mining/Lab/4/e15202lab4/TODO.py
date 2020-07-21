#!/usr/bin/env python
# coding: utf-8

# In[6]:


import numpy as np

#Importing Matplotlib
import matplotlib
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d #importing modules for 3D plotting


# In[7]:


# Fundamendals of plotting
plt.plot([1,2,3,4,5],[1,4,9,16,25]) #sample scatter plot 
plt.show() #display the plot


# In[37]:


# Figures and Subplots
t = np.arange(0., 5., 0.2)


# In[38]:


fig = plt.figure(figsize =(10 , 10)) #creating a figure 
fig.subplots_adjust(hspace =1.0)

axes_1 = plt.subplot (4,1, 1) #first axes in the figure
plt.plot(t, t,'r^',markersize=8,label='line1') #plotting with red marker ’^’
legend = plt.legend(loc='upper right', shadow=True,fontsize='x-large') #adding the legend 
plt.title('First Plot') #adding the title 
plt.xlabel('t') #labeling x axis 
plt.ylabel('t') #labeling y axis 
plt.xlim([0,10]) #limits of x axis

#Saving plots to ﬁle
plt.savefig('plot1.pdf') #saving the plot as a pdf 
plt.savefig('plot1.png',dpi =400,bbox_inches ='tight')

#jpg is not supported
#plt.savefig('plot1.jpg') #saving the plot as a jpg file 
#plt.savefig('plot11.jpg', dpi=100, quality=50, optimize=True, progressive=True) #jpg options

axes_2 = plt.subplot (4,1,2) #second axes in the figure 
plt.plot(t, t**2, 'b*',markersize=8) #plotting 
axes_2.set_title('Second Plot') #adding the title 
axes_2.set_xlabel('t') #labeling x axis 
axes_2.set_ylabel('t squred') #labeling y axis 
axes_2.set_ylim([0 ,40]) #limits of y axis


# In[47]:


# 3D plots
fig = plt.figure() #creating a figure 
ax = fig.add_subplot(111, projection='3d') #creating 3D subplot
xs=([29, 24, 25, 23, 30 ,31, 26, 26, 30, 28]) 
ys=([ 7, 53 , 33 , 66, 1 ,11, 91, 51, 83, 6]) 
zs=([-25, -25, -19, -23,-6, -9, -11 , -11,-5, 14])
ax.scatter(xs, ys, zs, c='r', marker='o')
ax.set_xlabel('X Label') 
ax.set_ylabel('Y Label') 
ax.set_zlabel('Z Label')

#Change the angle
ax.view_init(30, 30)
plt.show()

# In[ ]:





# In[ ]:




