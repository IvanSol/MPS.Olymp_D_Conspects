SET x=%CD%
cd /d %~dp0
call ./Qualification_round_1/texxify.bat
#call ./Qualification_round_2/texxify.bat
cd /d %x%