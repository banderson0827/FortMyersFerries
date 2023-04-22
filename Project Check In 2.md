# Fixed encryption of sensitive data

[View Commit](https://github.com/banderson0827/FortMyersFerries/commit/1374c2c98c41e42e9c51b9818a5fe66a937ecadd)

Here I fixed an issue from my last check-in where my encryption implementation was not correct. I followed the feedback provided by the instructor and changed my implementation to use the OpenSSL SHA256 hashing algorithm to generate hash values for hiding data. I am using this to create hashed usernames, passwords, and other sensitive data that is then stored as hashed values in the database. I implemented testing to ensure everything is working correctly this time. All hashes are printing to the console successfully for all pieces of information and there are no errors when running program to completion.



# Security testing implemented (improved so is now working) and Github settings used

* [View Code of Conduct Commit](https://github.com/banderson0827/FortMyersFerries/commit/38d1133b3becd19d088b2423ce14ee67cced9b6a)
* [View Security Policy Commit](https://github.com/banderson0827/FortMyersFerries/commit/96aadea356a388f4249380527a7899c967714dd3)
* [View Vulnerability Scanning Commit](https://github.com/banderson0827/FortMyersFerries/commit/dbb3c9c6a9be007f8c6ebdda97c26f4a4b97e4b9)

Here I used Github settings to create a security policy for the project as well as a code of conduct to govern behavior within the repository as well as procedures for reporting vulnerabilities, deploying patches, etc. I also fixed my vulnerability scanning because the previous tool Snyk does not appear to be detecting any issues. I switched to the Github integrated tool CodeQL for my vulnerability scanning. There were some errors initially and I had to manually configure some build script settings in the .yml to make it optimized for a C++ project and able to run. CodeQL is now successfully running to completion on the project whenever a push or pull request is made. The detected issues are put into a table in the Security tab in Github for easy review.

![image](https://user-images.githubusercontent.com/67702118/233760267-8464c4b6-5414-4e9d-96cb-dee14dc11cd2.png)



# Input Validation and Sanitization

[View Commit](https://github.com/banderson0827/FortMyersFerries/commit/447032db2055dc16703e7396b9fe3168506949be)

Here I implemented input validation and sanitization for the process of gathering input from the user for creating a new account. For each field, the input is validated for length requirements and sanitized to removed unexpected characters for certain fields (i.e. no numbers allowed in First Name). This is done to ensure that no garbage data is inserted into the database. Once input is sanitized and confirmed, it is hashed and eventually added to the database when the new account is created (inserted).



# Logging account creation, logins, and all transactions with database

Next I will be working on implementing the creation of the new user account in the database using SQlite3 with prepared statements. Along with this I will implement logging to generate log records for any change or query that is made to the database. This logging will cover new account creation, logins, ferry reservations, and any changes to database records.



# References
## Security Checklist
![image](https://user-images.githubusercontent.com/67702118/233760785-add8edb3-52ce-43cc-8a1d-712f168c0127.png)
![image](https://user-images.githubusercontent.com/67702118/233760812-0c7768d1-ee99-47ef-a244-6c6cec0ccb35.png)


