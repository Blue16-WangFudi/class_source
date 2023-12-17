import numpy as np
from utils.features import prepare_for_training

class LinearRegression:
    # 初始化数据
    def __init__(self, data, labels, polynomial_degree=0, sinusoid_degree=0, normalize_data=True):
        """
        1.对数据进行预处理操作
        2.先得到所有的特征个数
        3.初始化参数矩阵
        """
        '''
        这样可以进行多行注释
        '''
        (data_processed,
         features_mean,
         features_deviation) = prepare_for_training(data, polynomial_degree, sinusoid_degree, normalize_data=True)

        self.data = data_processed
        self.labels = labels
        self.features_mean = features_mean
        self.features_deviation = features_deviation
        self.polynomial_degree = polynomial_degree
        self.sinusoid_degree = sinusoid_degree
        self.normalize_data = normalize_data

        num_features = self.data.shape[1]
        self.theta = np.zeros((num_features, 1))

    # 这是一个训练函数，学习率alpha，迭代次数：num_iterations
    def gradient_descent(self,alpha,num_iterations):
        cost_history = []
        # 每一步都要执行一次迭代，进行更新
        # "_"表示占位符，没有实际作用
        for _ in range(num_iterations):
            self.gradient_step(alpha)
            cost_history.append(self.cost_function(self.data,self.labels))
# 梯度下降（gradient：梯度；descent：下降）
    def train(self,alpha,num_iterations=500):


    # 损失函数
    def cost_function(self,data,labels):
        num_examples = data.shape[0]
        delta= LinearRegression.hypothesis(self.data, self.theta)-labels
        cost=(1/2)*np.dot(delta,delta.T)
        return cost[0][0]
    def gradient_step(self,alpha):
        num_examples = self.data.shape[0]
        prediction=LinearRegression.hypothesis(self.data, self.theta)
        delta = prediction - self.labels
        theta = self.theta
        theta=theta-alpha*(1/num_examples)*(np.dot(delta.T,self.data))

    @staticmethod
    def hypothesis(data,theta):
        predictions=np.dot(data,theta)
        return predictions
    def get_cost(self,data,labels):
        data_processed=prepare_for_training(data,self.polynomial_degree)[0]

