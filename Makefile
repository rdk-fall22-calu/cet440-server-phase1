build: update-repo
	gcc src\\*.h src\\*.c -o build\\server

update-repo:
	git pull