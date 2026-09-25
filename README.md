# FreeRTOS

The goal here is to explore the basics for setting up and using FreeTROS. Unlike all my other projects to this point, I'll use Claude Code and perhaps some others, since I need to also learn what they can do. But the goal is still understanding, not the finish line, and I don't want those tools to get in the way of that.

I first asked Claude to make me a bare bones FreeRTOS project, without saying anything about hardware. It made.. something.. and claims it runs on Linux. Time to investigate!

Ok lol so first conflict is with this ReadMe file! Claude made its own, as part of its many changes in its own branch, and so I had Claude itself rename *this* file in the main branch, and it succeeded. That still left a merge conflict, but Claude was able to merge in such a way as to do what I want - keep both mine and its versions as separate files. It wasn't its default choice, but it warned me and presented options, and I told it what to do, in normal every day language. Afterwards I had it change up both names. 

I realize I'm a bit late to the party, but holy crap this is amazing and scary all at same time. In a world where anyone can just use plain language to accomplish highly technical things that often work, who will be left to understand systems when they don't?

Now to study the system starting point it gave me..
