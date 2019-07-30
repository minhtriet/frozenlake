## About this repo
Implementation of gridworld problem, Artificial Intelligence: A Modern Approach v3, Chapter 17. This is also similar to (Frozen Lake challenge) [https://gym.openai.com/envs/FrozenLake-v0/], which widely considers the most basic Reinforcement Learning (RL) problem.

The writing does not cover any thing, but things that can be easily overlooked when one implements not just this, but many machine learning papers in total.

## Motivation
The motivation of this is two fold:

1. According to Suttons’s book, there are two classes of RL, one that states and action space can be effectively stored on a table. Another case is that the states is innumberable (Number of Go/Dota/Starcraft moves) and need to have some approximation / generalization techniques.

While the latter case generates more hype, I find the former case good for education purpose. Not the magical blackbox of Neural Network, mostly non bullshit number.

2. After having my take of companies, I realize what is done anyway is throwing in data and a generic neural network (NN), I feel like it would be more beneficial to implement and debug some papers from scratch.


## Prerequiste
Know about basic concept of state, … in RL, I summarise them at the appendix. In this paper we use BFS with Bellman equation for value update.

Without further ado, I run to the problem and its two evasive pitfalls.

## The problem

The problem: Given this grid. An agent (or robot) can move to 4 direction, N, E, W, S.

```
 |----|----|----|----|
3| 🤖 |    |    | (+1) |
 |----|----|----|----|
2|    | x  |    | (-1) |
 |----|----|----|----|
1|    |    |    |    |
 |----|----|----|----|
   1    2    3    4 
```

Each time an agent (🤖) moves to a cell, it would receive a reward from that cell. The +1 and 1 is the end state, once the agent move to those cell, the game is over. x is an obstacle, which bounces the agent back when being hit.

The agent, however, has the probability to side step (p=0.1).

## Pitfalls
### Index matters
 When accessing a 2D array, the order of index often looks like
```
for i in range(rows):
    for j in range(columns):
        print(matrix[i][j])
```
However, common math convetion requies `x` coordinate (corresponds to `width`) comes before `y`, which conflicts with the `(height, width)` convention above. There also those kind of inconsistent, even in mature library (Compare https://docs.opencv.org/4.0.0/d3/d63/classcv_1_1Mat.html#a2ec3402f7d165ca34c7fd6e8498a62ca with https://docs.opencv.org/4.0.0/d3/d63/classcv_1_1Mat.html#a75a97b1e4e55f380c172af58048a7cde). 

If `width != height`, in a language like C++, instead of throwing an exception, a random number would be returned, which would lead to unpredictable result.

Solving this may requires altering one's convention
```
for i in range(width):
    for j in range(height):
        print(states[j][i])  # note the change of index here
```

It would be sensible to make one's own convention and to follow it to make it a habit.

### Initialization
Weight initialization gets a decent amount of attention (https://papers.nips.cc/paper/7338-how-to-start-training-the-effect-of-initialization-and-architecture.pdf, https://arxiv.org/pdf/1504.00941.pdf, https://twitter.com/ylecun/status/854136432327352320). Most profound effect is that setting wrong weight can lead to very slow or no learning at all. Luckily, we have a chance to experiment it in shallow learning too. 


The initial Bellman equation looks like:

<a href="https://www.codecogs.com/eqnedit.php?latex=\inline&space;U(s)&space;=&space;R(s)&space;&plus;&space;\gamma&space;max_{a&space;\in&space;A(s)}&space;P(s'|s,&space;a)U(s')" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\inline&space;U(s)&space;=&space;R(s)&space;&plus;&space;\gamma&space;max_{a&space;\in&space;A(s)}&space;P(s'|s,&space;a)U(s')" title="U(s) = R(s) + \gamma max_{a \in A(s)} P(s'|s, a)U(s')" /></a>

```
for i in range(width):
    for j in range(height):
        # move logic
        best_direction = null
        if best_result > value[i][j]:
            move_to_best_direction
```

Now with a board like this and a reward of 2, the result would never been update, since it is better to stay still than moving anywhere.

|   |   | ✥ | (1)  |
|---|---|---|------|
|   |   | ✥ | (-1) |

The correct policy would actually look like  following table

|   |   | ← | (1)  |
|---|---|---|------|
|   |   | ← | (-1) |

Intuitively, this world is so good no one wants to leave

## Appendix
_S_: States - Collection of snapshot of the enviroment by an agent
_U(s)_: Util - A value assigned to each state to show how valuable that state is
_R_: Reawrd - A value that the agent receive when it makes a move


## To run
### Compile
`./compile.sh`
### Run with different files
`./a.out [input.txt | input2.txt | ... ]`

