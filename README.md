## To run
### Compile
`./compile.sh`
### Run with different files
`./a.out [input.txt | input2.txt | ... ]`

## About this repo
Implementation of gridworld problem, Artificial Intelligence: A Modern Approach v3, Chapter 17, Exercise 11.

Reiforcement realing


## Motivation
The motivation of this is two fold:


1. Suttons’s bible In RL, there are two cases, one that states and action space can be effectively stored on a table. Another case is that the states 

While reality is the latter case, I find the former case good for education purpose. Not the magical blackbox of Neural Network, mostly non bullshit number.

2. After having my take of some data company and Internet blogs, I realize what is done anyway is throwing in data and a generic neural network (NN), I feel like it is  more beneficial to readers to either imp[lement a paper (and do debugging techniques like gradient check before tuning hyperparameters) 
or
2. Do some classical tabular RL method

The premise of RL is around Markov decision process, 

We use BFS with Bellman equation for value update



Index matters, make your own convention. If you says dimension of an rectangle is iwdth*height, and your index follows the convevntion of x axe before y axe, there is going to be a problem, instead of writing

```
for i in range(width):
    for j in range(height):
        states
```

Edge case matters

Experiments with different starting point, to see if policy changes

Why the over specific title.

Prerequiste: Know about basic concept of state, … in RL, I summarise them at the appendix

Common trap to falls to

OpenAI frozen lake challenge

If > 


However, if run, result would be


Book of Sutton called this in 2.6. Overall, it is highly depending on your initial value. As @Programmer says, hours of minutes of reading the manual


## Initialize condition
If one looks at the update condition


He might be tempted to write this

if (result > best_result) {
 71                     best_result = result;
 72                     best_direction = direction;
 73                 }

But in reality, code is a problem
