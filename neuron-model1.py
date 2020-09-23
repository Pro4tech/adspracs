# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
import numpy as np
import matplotlib.pyplot as plt

# %% [markdown]
# ### Unipolar Binary step
# 
# $$a^i_j = \sigma(x^i_j) = \begin{cases} 0  \hspace{1em} \text{if} \hspace{0.3em} x^i_j < 0 \\ 1 \hspace{1em} \text{if} \hspace{0.3em} x^i_j > 0 \end{cases}$$
# 

# %%
x = [-3, -2, -1, 0, 1, 2, 3]
y = [0, 0, 0, 0, 1, 1, 1]
plt.step(x, y)
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('step.svg', format='svg')

# %% [markdown]
# ### Bipolar Binary step
# 
# $$a^i_j = \sigma(x^i_j) = \begin{cases} -1  \hspace{1em} \text{if} \hspace{0.3em} x^i_j < 0 \\ 1 \hspace{1em} \text{if} \hspace{0.3em} x^i_j > 0 \end{cases}$$
# 

# %%
x = [-3, -2, -1, 0, 1, 2, 3]
y = [0, 0, 0, 0, 1, 1, 1]
plt.step(x, y)
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('step.svg', format='svg')

# %% [markdown]
# ### Tanh
# 
# $$a^i_j = \sigma(x^i_j) = \tanh(x^i_j)$$

# %%
x = np.arange(-5, 5, 0.1)


# %%
plt.plot(np.tanh(x))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('tanh.svg', format='svg')

# %% [markdown]
# ### Tanh (alternative equation)
# 
# $$a^i_j = \sigma(x^i_j) = \frac{2}{1+\exp(-2x^i_j)} - 1$$

# %%
plt.plot(2 / (1 + np.exp(-2*x)) - 1)
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('tanh-alternative.svg', format='svg')

# %% [markdown]
# ### ArcTan
# 
# $$a^i_j = \sigma(x^i_j) = \tanh^{-1}(x^i_j)$$

# %%
plt.plot(np.arctan(x))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('arctan.svg', format='svg')

# %% [markdown]
# ### Unipolar Sigmoid
# 
# $$a^i_j = \sigma(x^i_j) = \frac{1}{1+\exp(-x^i_j)}$$

# %%
plt.plot(1 / (1 + np.exp(-x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('sigmoid.svg', format='svg')

# %% [markdown]
# ### Bipolar Sigmoid
# 
# $$a^i_j = \sigma(x^i_j) = \frac{2}{1+\exp(-x^i_j)} -1 $$

# %%
plt.plot((2 / (1 + np.exp(-x)))-1)
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('sigmoid.svg', format='svg')

# %% [markdown]
# ### Complementary log-log
# 
# $$a^i_j = \sigma(x^i_j) = 1 − \exp\!\big(−\exp(x^i_j)\big)$$

# %%
plt.plot(1 - np.exp(-np.exp(x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('complementary-log-log.svg', format='svg')

# %% [markdown]
# ### Bipolar Sigmoid
# 
# $$a^i_j = \sigma(x^i_j) = \frac{1-\exp(-x^i_j)}{1+\exp(-x^i_j)}$$

# %%
plt.plot((1 - np.exp(-x)) / (1 + np.exp(-x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('bipolar-sigmoid.svg', format='svg')

# %% [markdown]
# ### LeCun's Tanh
# 
# $$a^i_j = \sigma(x^i_j) = 1.7159 \tanh\!\left( \frac{2}{3} x^i_j\right)$$

# %%
plt.plot(1.7159 * np.tanh(2/3 * x))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('lecuns-tanh.svg', format='svg')

# %% [markdown]
# ### Hard Tanh
# 
# $$a^i_j = \sigma(x^i_j) = \max\!\big(-1, \min(1, x^i_j)\big)$$

# %%
plt.plot(np.maximum(-1, np.minimum(1, x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('hard-tanh.svg', format='svg')

# %% [markdown]
# ### Absolute
# 
# $$a^i_j = \sigma(x^i_j) = \mid x^i_j \mid$$

# %%
plt.plot(np.absolute(x))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('absolute.svg', format='svg')

# %% [markdown]
# ### ReLU (Rectified Linear Unit)
# 
# $$a^i_j = \sigma(x^i_j) = \max(0, x^i_j)$$

# %%
plt.plot(np.maximum(0, x))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('relu.svg', format='svg')

# %% [markdown]
# ### Smooth ReLU
# $$a^i_j = \sigma(x^i_j) = \log\!\big(1+\exp(x^i_j)\big)$$

# %%
plt.plot(np.log(1 + np.exp(x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('smooth-relu.svg', format='svg')

# %% [markdown]
# ### Leaky ReLU
# 
# $$a^i_j = \sigma(x^i_j) = \max(0.01 x^i_j, x^i_j)$$

# %%
z = np.arange(-55, 5, 1)
plt.plot(np.maximum(0.01 * z, z))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('leaky-relu.svg', format='svg')

# %% [markdown]
# ### Logit
# 
# $$a^i_j = \sigma(x^i_j) = \log\!\bigg(\frac{x^i_j}{(1 − x^i_j)}\bigg)$$

# %%
z = np.arange(-17, 17, 0.000001)
plt.plot(np.log(z / (1 - z)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('logit.svg', format='svg')

# %% [markdown]
# ### Softmax
# 
# $$a^i_j = \sigma(x^i_j) = \frac{\exp(z^i_j)}{\sum\limits_k \exp(z^i_k)}$$

# %%
plt.plot(np.exp(x) / np.sum(np.exp(x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('softmax.svg', format='svg')


# %%
plt.plot(np.tanh(x))
plt.plot(1 / (1 + np.exp(-x)))
plt.plot(np.maximum(0, x))
plt.plot(np.exp(x) / np.sum(np.exp(x)))
plt.show()


# %%
plt.plot(1 / (1 + np.exp(-x)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('sigmoid1.svg', format='svg')

# %% [markdown]
# #### Identity function
# $$

# %%
plt.plot(x)
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('Identity.svg', format='svg')

# %% [markdown]
# ### Unipolar Piecewise linear
# $$

# %%
plt.plot(np.minimum(np.maximum(x,np.zeros(x.shape)),np.ones(x.shape)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('Unipolar Piecewise linear.svg', format='svg')

# %% [markdown]
# ### Bipolar Piecewise Linear

# %%
plt.plot(np.minimum(np.maximum(x,np.ones(x.shape)*(-1)),np.ones(x.shape)))
plt.grid(True)
plt.xlabel('x', fontsize=15)
plt.ylabel('f(x)', fontsize=15)
plt.savefig('Unipolar Piecewise linear.svg', format='svg')

# %% [markdown]
# ### write a code to generate output of neuron using diffrent activation functions 

# %%
ip=np.random.choice([0,1],size=100)
print(ip.shape)
w=np.random.choice([1,-1],size=100)
# w=np.transpose(w)
print(w.shape)
ip=np.array([1,0,1,0,1])
w=np.array([1,-1,1,1,-1])
print(sum(ip*w))
s=sum(ip*w)
print(s)


# %%



