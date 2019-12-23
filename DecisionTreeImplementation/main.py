from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score, classification_report
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

#model evalustion before pruning
print("Model evaluation before pre pruning:\n")
y_pred = tree1.predict(x_test)
conf_metrix = confusion_matrix(y_test, y_pred)
print("Confusion Matrix: \n", conf_metrix)
print("Accuracy : ", accuracy_score(y_test, y_pred) * 100)
print("Report : \n", classification_report(y_test, y_pred))

#train model using decision tree with pre pruning
tree2 = DecisionTreeClassifier(criterion="entropy", max_depth=3, min_samples_leaf=5, max_leaf_nodes=5)
tree2.fit(x_train, y_train)

#train model using decision tree with pre pruning
tree2 = DecisionTreeClassifier(criterion="entropy", random_state=42)
tree2.fit(x_train,y_train)

#model evalustion after pruning
print("\n\nModel evaluation after pre pruning:\n")
y_pred = tree2.predict(x_test)
conf_metrix = confusion_matrix(y_test, y_pred)
print("Confusion Matrix: \n", conf_metrix)
print("Accuracy : ", accuracy_score(y_test, y_pred) * 100)
print("Report : \n", classification_report(y_test, y_pred))



