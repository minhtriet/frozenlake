## To run
### Compile
`./compile.sh`
### Run with different files
`./a.out [input.txt | input2.txt | ... ]`

## About this repo
Implementation of gridworld problem, Artificial Intelligence: A Modern Approach v3, Chapter 17, Exercise 11.
We use BFS with Bellman equation for value update

If you look at the result, abnormally

Index matters, make your own convention. If you says dimension of an rectangle is iwdth*height, and your index follows the convevntion of x axe before y axe, there is going to be a problem

Edge case matters

Experiments with different starting point, to see if policy changes

Why the over specific title.

Prerequiste: Know about basic concept of state, … in RL, I summarise them at the appendix

Suttons’s bible In RL, there are two cases, one that every states can be effectively stored on a table.

While reality is the latter case, I find the former case good for education purpose. Not the magical blackbox of Neural Network, mostly non bullshit number.

Common trap to falls to

OpenAI frozen lake challenge

If > 


However, if run, result would be


Book of Sutton called this in 2.6. Overall, it is highly depending on your initial value. As @Programmer says, hours of minutes of reading the manual
