# BlankOS App Store Backend

This is the official repository for BlankOS `.bloe` applications. 

## How to use this folder:
1. Open your terminal and `cd` into this `store_repo` folder.
2. Run `git init` to make this its own separate Git repository.
3. Commit the `catalog.json` and push it to a new GitHub repository (e.g., `https://github.com/airskye1/blankOS-App-Store`).
4. Update `f:\blankOS\src\apps\store.c` in your main OS code to point to the raw URL of this `catalog.json`!

Any developer who wants to publish an app for BlankOS can just submit a Pull Request to this repository, adding their `.bloe` file to the `apps/` folder and updating the `catalog.json`!
