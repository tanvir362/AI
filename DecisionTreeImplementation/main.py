from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn import metrics
import pandas as pd
import numpy as np

#load data
data = pd.read_csv("iris.csv", header=None)
data.columns = ['sepal length', 'sepal width', 'petal length', 'petal width', 'class']
print(data.head())

#separating features and target
x = np.array(data.drop(['class'], 1))  # axis 1 denotes columns axis 0 denotes rows
y = np.array(data['class'])

#spliting traing and test set
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3)

#train model using decision tree without pruning
tree1 = DecisionTreeClassifier(criterion="entropy", random_state=42)
tree1.fit(x_train,y_train)

#model evalustion
y_pred = tree1.predict(x_test)
print("Accuracy:", metrics.accuracy_score(y_test, y_pred))



