# SE-Lab-2
In this Task-2, the previously single-file implementation (main.c) has been extended and restructured into multiple modules following software engineering principles such as high cohesion, low coupling, reusability, and maintainability.

Input & Validation
-->Reads student details from an input file 
-->validates:
   >Student ID (alphanumeric, unique)
   >Student Name (alphabets only)
   >Minor marks (0–40)
   >Major marks (0–60)
-->Logs invalid records into an error file

Computation
>Computes:
  >Subject-wise grades
  >Total marks
  >Percentage
  >CGPA
>Determines:
  >Class average percentage
  >Highest and lowest percentage
  >Grade-wise student distribution

Output
-->Generates a student report (output.txt)
-->Generates an error log (error.txt)



