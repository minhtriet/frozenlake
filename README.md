# Overlooked details on implementing papers
And how to prevent them

## About this repo
Implementation of the grid world problem, Artificial Intelligence: A Modern Approach v3, Chapter 17. This is also similar to the [Frozen Lake challenge](https://gym.openai.com/envs/FrozenLake-v0/), which is widely considered a basic Reinforcement Learning (RL) problem.

The writing cover  things that can be overlooked when one implements not just this algorithm, but also many other papers.

## Motivation
The motivation of this is two-fold:

1. According to Suttons’s book, there are two classes of RL, one that states and action space can be stored in a table. Another case is that the number of states is innumerable (Number of Go/Dota/Starcraft moves). Solving this would require some approximation/generalization techniques.

While the latter case generates more hype, I find the former case good for education purposes.

2. After having my take of companies, I realize what is done anyway is throwing in data and a generic neural network (NN), I feel like it would be more beneficial to implement and debug some papers from scratch.


## Prerequisites
Know about the basic concept of state, … in RL, I summarise them in the appendix. In this implementation, we use BFS with the Bellman equation for value updating.

Without further ado, I run to the problem and its two evasive pitfalls.

## The problem

Given the grid below. An agent (or robot) can move to 4 direction, N, E, W, S.

|   |   |   | (1)  |
|---|---|---|------|
|   | ✗ |   | (-1) |
| 🤖 |   |   |      |
   

Each time an agent (🤖) moves to a cell, it would receive a reward from that cell. The (1) and (-1) is the end state, once the agent move to one of those cells, the game is over. `✗` is an obstacle, which bounces the agent back when being hit.

The agent, however, has the probability to sidestep (p=0.1)
```
Sidestep (p=0.1)
↑
xx ----> Intended direction (p=0.8)
↓
Sidestep (p=0.1)
```
Find the optimal policy for the agent. For example, with a reward of -0.04 per cell, the optimal policy is
```
→  →  →  ✗
↑  ✗  ↑  ✗
↑  ←  ↑  ←
```
## Solution
We can use the Bellman equation

<a href="https://www.codecogs.com/eqnedit.php?latex=\inline&space;U(s)&space;=&space;R(s)&space;&plus;&space;\gamma&space;max_{a&space;\in&space;A(s)}&space;\sum_{s'}P(s'|s,&space;a)U(s')" target="_blank"><img src="https://latex.codecogs.com/png.latex?\inline&space;U(s)&space;=&space;R(s)&space;&plus;&space;\gamma&space;max_{a&space;\in&space;A(s)}&space;\sum_{s'}P(s'|s,&space;a)U(s')" title="U(s) = R(s) + \gamma max_{a \in A(s)} \sum_{s'}P(s'|s, a)U(s')" /></a>

and its extended form: Note that (1, 1) is the bottom left corner
```
U(1,1)=−0.04+γ max[ 0.8U(1,2)+0.1U(2,1)+0.1U(1,1),               (Up)
                    0.9U (1, 1) + 0.1U (1, 2),                   (Down)
                    0.9U (1, 1) + 0.1U (2, 1),                   (Left)   
                    0.8U (2, 1) + 0.1U (1, 2) + 0.1U (1, 1) ].   (Right)
```

## Pitfalls
### Index matters
 When accessing a 2D array, the order of index often looks like
```
for i in range(rows):
    for j in range(columns):
        print(matrix[i][j])
```
However,  math convention requires `x` coordinate (corresponds to `width`) comes before `y`, which conflicts with the `(height, width)` convention above. This kind of inconsistent creeps into even mature libraries (Compare https://docs.opencv.org/4.0.0/d3/d63/classcv_1_1Mat.html#a2ec3402f7d165ca34c7fd6e8498a62ca with https://docs.opencv.org/4.0.0/d3/d63/classcv_1_1Mat.html#a75a97b1e4e55f380c172af58048a7cde). 

If `width != height`, in a language like C++, instead of throwing an exception, a random number would be returned, which would lead to unpredictable results.

Solving this may requires altering one's convention
```
for i in range(width):
    for j in range(height):
        print(states[j][i])  # note the change of index here
```

It would be sensible to make one's convention and to follow it to make it a habit.

### Initialization
Weight initialization gets a decent amount of attention (https://papers.nips.cc/paper/7338-how-to-start-training-the-effect-of-initialization-and-architecture.pdf, https://arxiv.org/pdf/1504.00941.pdf, https://twitter.com/ylecun/status/854136432327352320). The most profound effect is that setting the wrong weight can lead to very slow or no learning at all. Luckily, we have a chance to replicate this in shallow learning too. 

```
for i in range(width):
    for j in range(height):
        # move logic
        best_direction = null
        if best_result > value[i][j]:
            move_to_best_direction
```

With a board like this and a reward of 2, the result would never be updated. It is better to stay still than moving anywhere.

|   |   | ✥ | (1)  |
|---|---|---|------|
|   |   | ✥ | (-1) |

The correct policy would look like the following table

|   |   | ← | (1)  |
|---|---|---|------|
|   |   | ← | (-1) |

This world is so good no one wants to leave

## Appendix
- _S_: States - Collection of a snapshot of the environment by an agent
- _U(s)_: Util - A value assigned to each state to show how valuable that state is
- _R_: Reward - A value that the agent receives when it makes a move

## To run
### Compile
`./compile.sh`
### Run with different files
`./a.out [input.txt | input2.txt | ... ]`
