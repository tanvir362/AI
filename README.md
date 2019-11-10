File and folder contents I used and need to remember:

TitanicDisaster:
  1.	Dropping non-numeric columns
  2.	Mapping nominal non-numeric data with numeric value
  3.	Missing value count of every column
  4.	Filling missing values(mean, frequent)
  5.	Frequency count of column values
  6.	Separating features and target
  7.	Train test splitting
  8.	Applying Support Vector Machine algorithm
  9.	Evaluation(accuracy, precision, recall)

RosenblattPerceptron.cpp:
  1.	Perceptron class with constructor
  2.	Private fields: weights, bias, learning rate
  3.	Public methods: update,  training, test 
  4.	Solve AND, OR problem

BackPropagationLab.cpp:
  1.	Node(perceptron) class with constructor
      •	Fields: weights, bias 
      •	Methods: net calculate, activation(sigmoid)
  2.	BackPropagation class, constructor creates necessary perceptron for the network
      •	Methods:
        Training: creates network using previously created perceptrons, find errors and updates
        Update: Updates every nodes weights and bias
        Test: find output of the network y from given input x1 and x2

statistical_analysis_HCV-Egy-Data.ipynb:
  1.	Statistical analysis(correlation, mean, median, percentile, standard deviation, outlier, etc)
  2.	Find feature attributes correlation with class attribute
  3.	Top 5 feature attribute selection with maximum correlation with class attribute
  4.	Box plot to detect outlier
  5.	Dropping rows contains outlier
  6.	Parallel coordinate plotting

pca_knn_iris.ipynb:
  1.	Load csv data and set columns name
  2.	Separating features and target(using drop)
  3.	Idea about axis of dataset
  4.	Splitting train and test set
  5.	Applying k-nearest neighbors (KNN)
  6.	PCA analysis
  7.	Evaluation(accuracy)


