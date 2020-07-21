#!/usr/bin/env python
# coding: utf-8

# In[151]:


from mlxtend.frequent_patterns import apriori
from mlxtend.frequent_patterns import association_rules
from mlxtend.preprocessing import TransactionEncoder
import pandas as pd
import numpy as np
import math


# In[152]:


#Import dataset
store_data = pd.read_csv('grocc.csv',header=None)


# In[153]:


print("Dataset =\n",store_data)


# In[154]:


# convert our pandas dataframe into a list of lists,
records = []
for i in range(0, 9835):
    rowItem = []
    for j in range(0, 32):
        if str(store_data.values[i,j]) == 'nan':
            break
        rowItem.append(str(store_data.values[i,j]))
    records.append(rowItem)
    #records.append([str(store_data.values[i,j]) for j in range(0, 32)])
    
print("Dataset list without nan = \n",records)


# In[155]:


#Creating the dataframe of frequent itemsets
te = TransactionEncoder()
te_ary = te.fit(records).transform(records)
df = pd.DataFrame(te_ary, columns=te.columns_)


# In[157]:


#Finding the support
#min_support parameter is used to select the items with support values greater than the value specified by the parameter
sup = apriori(df, min_support=0.1,use_colnames=True)


# In[158]:


print("Support =\n",sup)


# In[168]:


rules= association_rules(sup, metric="lift", min_threshold=0.1)


# In[169]:


print("Association rules =\n",rules)


# In[167]:


#there are no any association rules for the support > 0.1 and lift > 0.1 


# In[177]:


#selecting minimum support as 0.002
#Finding the support
#min_support parameter is used to select the items with support values greater than the value specified by the parameter
sup = apriori(df, min_support=0.002,use_colnames=True)
print("Support =\n",sup)


# In[178]:


rules= association_rules(sup, metric="lift", min_threshold=1)
print("Association rules =\n",rules)


# In[180]:


#(e) Select any Association rule from the set and describe the selected rule.

#Selected :- first association rule (row number 0)

#support defined as support(A->C)
#Where A is antecedent and C is consequent
#A = hamburger meat
#C = Instant food products
#antecedent support = (Transactions containing (hamburger meat))/(Total Transactions) = support(A)
#consequent support = (Transactions containing (Instant food products))/(Total Transactions) = support(C)
#support = support(A->C) = (Transactions containing (A U C))/(Total Transactions)

#Confidence(A→C) = (Transactions containing both (A and C))/(Transactions containing A)
#Confidence refers to the likelihood that an item C is also bought if item A is bought.
#Therefore confidence = 0.091743 means that
#the likelihood of buying Instant food products if hamburger meat is bought = 0.091743

#Lift(A→C) = (Confidence (A→C))/(Support (C))
#Lift(A -> C) refers to the increase in the ratio of sale of C when A is sold
#So sale of Instant food products is increased by 11.421438 of ratio when hamburger meat is sold

#levarage(A→C)=support(A→C)−support(A)×support(C)
#Leverage computes the difference between the observed frequency of A and C appearing together and the frequency that would be expected if A and C were independent. 
#An leverage value of 0 indicates independence.

#conviction(A→C) = (1−support(C))/(1−confidence(A→C))
#A high conviction value means that the consequent is highly depending on the antecedent.
#Similar to lift, if items are independent, the conviction is 1.
#The conviction value says that buying Instant food products is 1.092166 depedns on buying hamburger meat


# In[186]:


#(f) How many rules are there when the ’lift’ is greater than 4 and the ’confidence’ is greater than 0.8.

#support > 0.002
#lift > 4
#confidence > 0.8
rules[(rules['confidence'] > 0.8) & (rules['lift'] > 4) ]


# In[187]:


print(rules[(rules['confidence'] > 0.8) & (rules['lift'] > 4) ])


# In[188]:


#According to the above print statement there is only one rule that satisfy the given conditions


# In[ ]:




