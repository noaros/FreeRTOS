# FreeRTOS + Claude

The goal here is to explore the basics for setting up and using FreeTROS. Unlike all my other projects to this point, I'll use Claude Code and perhaps some others, since I need to also learn what they can do. But the goal is still understanding, not the finish line, and I don't want those tools to get in the way of that.

I first asked Claude to make me a bare bones FreeRTOS project, without saying anything about hardware. It made.. something.. and claims it runs on Linux. Time to investigate!

Ok lol so first conflict is with this ReadMe file! Claude made its own, as part of its many changes in its own branch, and so I had Claude itself rename *this* file in the main branch, and it succeeded. That still left a merge conflict, but Claude was able to merge in such a way as to do what I want - keep both mine and its versions as separate files. It wasn't its default choice, but it warned me and presented options, and I told it what to do, in normal every day language. Afterwards I had it change up both names. 

I realize I'm a bit late to the party, but holy crap this is amazing and scary all at same time. In a world where anyone can just use plain language to accomplish highly technical things that often work, who will be left to understand systems when they don't?

Except... Ha ha ha Claude lied to me. It told me one file had its branch's version untouched, but actually it merged my version in with it. Oh well.. Live by the sword die by the sword.

It made me something weird, just using a POSIX wrapper between Linux and FreeRTOS to act as a simulator of real hardware. And it works.
I followed its build instructions (had to install cmake), ran it, and voila, printed output on screen.

<img width="444" height="396" alt="image" src="https://github.com/user-attachments/assets/84da6dc7-c5a6-4e3c-bc5b-f85b50009db9" />

 This isn't what I want of course, but is interesting enough for me to stop and study it awhile.

 I believe it gave me something based on the "FreeRTOS POSIX Simulator" and documented here:
 
 https://freertos.org/Documentation/02-Kernel/03-Supported-devices/04-Demos/03-Emulation-and-simulation/Linux/FreeRTOS-simulator-for-Linux.

Now I know!

So I think I will detour a bit and just build up the FreeRTOS demo manually the old fashioned way. I shoved the Claude version into its own directory, but bumped up the FreeRTOS directory expecting to be shared with the manual demo. Adjusted CMake config so the Claude app works with the change. 
