# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Doorbell

```mermaid
flowchart TD
    Start([Doorbell])
    GetButtonStatus(Get Button Status)
    CheckButton{has button been pressed}
    SoundDoorBell(play Sound)
    finish([end])

    Start-->GetButtonStatus-->CheckButton
    CheckButton-->|Yes| SoundDoorBell
    CheckButton-->|No| finish
    SoundDoorBell-->finish    
```
## Door locker
```mermaid
flowchart TD
    Start([Doorlocker])
    getSonarDistance(Get Distance)
    checkSonarDistance(check Distance)
    closeAndLockDoor(Close and Lock Front Door)
    keepDoorInPlace(keep Door in Place)
    finish([end])

    Start-->checkSonarDistance
    checkSonarDistance-->|Within range| closeAndLockDoor
    checkSonarDistance-->|Out of range| keepDoorInPlace 
    closeAndLockDoor--> finish    
```
##   SD Card Info 
```mermaid
flowchart TD
    Start([SD card]) -->
    Log(info to card) -->
    Info 
```

## Alarm System 
```mermaid 
flowchart TD
    Start([PIR])
    GetPIRStatus(Get PIR Status)
    CheckPIR{Has Infared been detected}
    SoundAlarm(Turn Lights On)
    finish([end])
    
    Start-->GetPIRstatus-->CheckPIR
    CheckPIR-->|Yes| SoundAlarm
    CheckPIR-->|No| finish
    SoundAlarm-->finish    

```