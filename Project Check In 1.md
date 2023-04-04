# Sensitive data is encrypted (usernames, passwords, database, etc.)
[View Commit](https://github.com/banderson0827/FortMyersFerries/commit/c1e3256d09dad7ae18e3aad82d90955ea4a8bb77)
Explanation of work completed in the commit description.


# Security Testing Used
There is no commit for this item.

I acquired and integrated Synk, an open-source vulnerability scanning tool. I began by linking my Github account with Synk and then adding my
repository to be scanned. I also integrated the command line tool that comes with it to monitor the code base at all times for outdated 
dependencies, known vulnerabilities, etc. I also integrated the tool into my IDE to proactively suggest actions to eliminate vulnerabilites 
as I am coding.
![image](https://user-images.githubusercontent.com/67702118/229679829-116eb95d-42a7-43d7-a30c-59dd6adb716e.png)


# Next Items to be Attempted
* Accounting: Process includes logging (tracking of changes, user making changes, access attempts, etc).
  * Priority: High
  * Difficulty: Moderate
  * I will implement the generation of .log files for account creation, logins, ferry reservations, and any transaction within the database.
* Accounting: Logging is integrated into the code itself (for exceptions, errors, and user input failures at minimum).
  * Priority: High
  * Difficulty: Difficult
  * I will implement input validation for getting usernames, passwords, etc. to ensure criteria are met and input is sanitized.
* Backup Policy is in place and being used.
  * Priority: High
  * Difficulty: Easy
  * I will create a backup for the source code and the database.
* The cloud based platform provides for hiding information and this is used to protect sensitive information and code.
  * Priority: Mid
  * Difficulty: Difficult
  * I will implement a MVC (Model-View-Controller) structure with the application to hide the raw database data.



