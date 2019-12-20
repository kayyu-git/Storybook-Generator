# Storybook-Generator

A C++ program that makes use of vectors to create a text-based choose-your-own-adventure storybook that responds to user input. The contents of the storybook are read from a text file, and at certain points in the story, the user can enter a number to indicate his/her choice from a variety of options. 

The story can be edited under story.txt. To add content to the story, indicate text with [Node Text], text on the next line, and [Node End].

To add options to the text, indicate option text with [Node Option Text], a number for the user to enter to indicate the option and the text on the next line, [Node Option Next], and the vector index of the [Node Text] that the option should lead to. If the option requires a stat check, indicate so with [Node Option Stat], followed by the stat checked on the next line. Signal the end of the option with [Node Option End].
