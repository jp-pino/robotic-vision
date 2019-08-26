#
# The rule for making a project.
#
project:
	@if [[ \"${NAME}\" != \"\" ]];														\
	then																											\
		echo "  NEW PROJECT: " ${NAME} &&												\
		cp -r .template ${NAME};																\
	else																											\
	  echo "  ERROR: use as \`make project NAME=[name]\` ";		\
	fi																												\
