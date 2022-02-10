# 100 Days Of Code - Log

### Day 1: 08-02-2022

**Today's Progress**: setup for development, testing file size and memories of NUC240 microcontroller,

**Thoughts:** Tried to visualize data in memory view. 
Viewing RAM was easy but it took time to reflact the memory in flash.

**Link to work:** none

### Day 2: 09-02-2022

**Today's Progress**: I2C communication failed to initiate.

**Thoughts:** I tried to do I2C communication but initialization failed.
Also I accidently deleted the day1 folder, so I have to get that back from git.
Figuring that out also took some time.

### Day 2: 09-02-2022

**Today's Progress**: I2C communication configuration.

**Thoughts:** I2C configurated to 100kbps.
The datasheet says config MFP, enable clock and then reset module for initialization.
Speed was not getting set. Found a way to look into the peripharal registers in eclipse.
After some time got to know that reset module stops it.
After skipping the reset step, I2C configured properly.

