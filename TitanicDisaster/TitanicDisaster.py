import numpy as np
import pandas as pd
from sklearn import svm
from sklearn.model_selection import train_test_split
from sklearn import metrics

df = pd.read_csv("train.csv")
df = df.drop(columns = ['name','ticket','cabin'])
df['sex'] = df['sex'].map({'female' : 0, 'male' : 1})
df['embarked'] = df['embarked'].map({'C' : 1, 'Q' : 2, 'S' : 3})
#missing value count of every coulmn
#print(df.isnull().sum())
#printing embarded value frequency
#print(df['embarked'].value_counts())
#fill missing value with 3
df['embarked'].fillna(3, inplace = True)

#print(df['age'].mean())
df['age'].fillna(df['age'].mean(), inplace = True)
#print(df.isnull().sum())
#print(df.age)
X = df.loc[:,'pclass' : 'embarked']
Y = df['survived']
#print(X)
#print(Y)

X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.3,random_state=109) # 70% training and 30% test
model = svm.SVC(kernel = 'linear')
model.fit(X_train, y_train)

#Predict the response for test dataset
y_pred = model.predict(X_test)
#print(y_pred)
print("Accuracy:",metrics.accuracy_score(y_test, y_pred))
print("Precision:",metrics.precision_score(y_test, y_pred))
print("Recall:",metrics.recall_score(y_test, y_pred))

#print(df.columns)
