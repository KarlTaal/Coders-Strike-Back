# Coders-Strike-Back
Test assignment from Milrem Robotics.
## Overview
I really love competitions and I get easily addicted to them. So this test assignment is by far the coolest one I have done so far! I have done some coding in CodinGame before, but it was more like a glimpse to it. Therefore I knew already something about CodinGame before I started and got my pod moving very quickly because of that.
In university, we have been coding mainly in Java and Python, but in this semester I took an elective course that introduces C++. As I saw that internship will be also in C++, then I chose that language also for programming my fearful racing bot. At first, I did not really care how my code looked like because at first, I did not have much information to work on with my bot and therefore the code was short. As I got more information about the game when I reached higher leagues, I added little by little more code without that my code getting incomprehensive. When I reached to Silver, then I decided to refactor the code to clear things up.
As I reached higher leagues I started to read countless forum posts about coders strike back. I got new ideas from people and some intuition what will happen in higher leagues. For example, getting additional pod to control etc.

## Wood to Bronze
Few hours after I started programming my pod I was already in the Bronze League. I got there quick and thus of that, I did not capture middle states of my code and that is why the first code in the repository is about reaching to Silver League. 
In this stage, I had to implement simple thrust control and if I remember correctly then I had also a one time BOOST to use.  I followed simple logic that if I got closer to the checkpoint I set thrust to a smaller value and also when the angle was too big I set the thrust to zero to correct the course. That took me into the Bronze League.

## Bronze to Silver
### Intro     
This is the stage where the real fun began. With my simple solution, I got something like 22000/23000 place in the scoreboard. I got extra information about opponents coordinates and also the shield was introduced, but I ended up not using either of them to reach silver. 

### Thrust control     
To reach silver I knew that my thrust control was definitely too primitive. I implemented a control system that increased the thrust when the angle was smaller and vice versa. Before the thrust was changing just between a couple of values, but now the thrust changes accordingly to the angle. 

### Start turning before passing the checkpoint     
Addition to that I saw that my pod started to turn for next checkpoint after it passed current checkpoint so I thought that it would be awesome if it starts turning to next checkpoint a bit earlier. But how do I know where is the next checkpoint? Well, that's easy. For the first lap, I just assumed that the next checkpoint after the current objective is in the middle of the field and started to turn to this direction a bit before I passed the current objective and the second I got information about next checkpoint I turned for that. After the first lap, the bot had a record of every checkpoint in the field and therefore since lap 2, the pod knew every time where will the next checkpoint be after passing current objective and it started to turn to this direction a bit earlier.    

### Improved boost usage     
Now when I had implemented the remembering where the checkpoints are I also thought to reimplement how the BOOST is used. I was able to calculate what is the longest distance between two checkpoints and therefore I set following rules to use the BOOST:
If the lap number is 3 and BOOST is not used, then use it to boost for the finish.
If the lap number is >1 and the pod is going to race between checkpoints with the longest distance then boost. That of course only when the distance is enough long and angle is good.   

### Preventing pod to miss checkpoint because of inertia     
With implementing lastly mentioned things, my pod got approximately 7000th place in the scoreboard. I examined why my pod had lost against some opponents and I saw that sometimes when the next checkpoint was close and the pod tried to turn for that with too much thrust, then it slid past the checkpoint very closely. So I added one more thrust control "if clause" that adjusted the trust to 30 if speed was larger than 180 and angle was bigger than 3. Then the pod corrected its course slightly and started speeding again when the angle was good enough. That adjustment took me to the first place in the scoreboard with ease and I got promoted to Silver League!

## Silver to Gold
### Intro     
At this point I really did not have a good idea what to do next since I did not receive really any additional info about the game. I got only the SHIELD to use now for extra thing. Since I had ignored collisions so far I tought that I should implement some kind of functionality that deals with collisions.

### Parameters
Very first thing I did was actually adjusting some parameter values and that took me pretty good place in scoreboard. Just by changing some values...

### Attack the opponent
My idea was following: 
Ingore the SHIELD opportunity and do not use it at all, because the info that my pod will deactive for 3 turns after that kind a scared me. Attack opponent with BOOST instead when suitable.   
I implemented that functionality with one very long and and ugly if clause when to BOOST towards the enemy pod. I aimed the situtation where both our pods are thrusting to checkpoint at full speed. Now when the enemy pod is slightly ahead of me and I have BOOST to use then I BOOST towards the enemy pod hoping to knock it off the course and ideal scenario would be that I will pass the checkpoint but enemy's pod will be knocked away without going through the checkpoint. That worked like a charm! I got first place in leaderboard and got promoted to the Gold League!



