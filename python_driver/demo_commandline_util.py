
from Tkinter import *
import tkMessageBox
import tkFileDialog as filedialog
import subprocess
import os

class demoutil(Frame):
    def __init__(self, parent, str_filename=''):
        Frame.__init__(self, parent)
        self.parent = parent
        self.create_widgets()

    def create_widgets(self):

        self.parent.title("Demo c plus plus command line util")
        self.pack(fill=BOTH, expand=1)

        #col 1 fills unused columns
        self.columnconfigure(1, weight=1)

        # label1 = Label(self,
        #                text="Choose exe\n",
        #                justify=LEFT)
        # label1.grid(row=0, column=0, columnspan=4, sticky=W, padx=5, pady=5)
        ######################
        #create a button and text to select exe
        find_cmd_button = Button(self, text="Choose exe", command=self.select_cmd_util)
        find_cmd_button.grid(row=1, column=0, sticky=W, padx=5, pady=5)

        self.txt_cmd_util = Entry(self)
        self.txt_cmd_util.grid(row=1, column=1, columnspan=3, sticky=W + E, padx=5, pady=5)

        ######################
        # create another button and text to select data file
        find_datafile_button = Button(self, text="Choose data file", command=self.select_data_file)
        find_datafile_button.grid(row=2, column=0, sticky=W, padx=5, pady=5)

        self.txt_data_file = Entry(self)
        self.txt_data_file.grid(row=2, column=1, columnspan=3, sticky=W + E, padx=5, pady=5)

        ######################
        #get pass and fail output files
        label1 = Label(self,text="enter fail and pass files\n",justify=LEFT)
        label1.grid(row=3, column=0, columnspan=4, sticky=W, padx=5)

        self.fail_file = Entry(self)
        self.fail_file.insert(0, "PassFileName")
        self.fail_file.grid(row=4, column=0, columnspan=3, sticky=W + E, padx=5)

        self.pass_file = Entry(self)
        self.pass_file.insert(0,"FailFileName")
        self.pass_file.grid(row=5, column=0, columnspan=3, sticky=W + E, padx=5)

        self.lb_del_files = Button(self, text="Run", command=self.run_cmd)
        self.lb_del_files.grid(row=9, column=0, sticky=W, padx=5)

    def select_cmd_util(self):
        # TODO filepicker
        self.cmd_file = filedialog.askopenfilename(initialdir = "/home/keith/workspace_327/4_Vector_StudentGrades/Debug")

        #what directory is it in
        self.dir = os.path.dirname(self.cmd_file)

        #what is the file part
        file = os.path.basename(self.cmd_file)

        self.txt_cmd_util.delete(0, END)
        self.txt_cmd_util.insert(0, file)

    def select_data_file(self):
        # TODO filepicker
        self.data_file = filedialog.askopenfilename(initialdir=self.dir)

        # what is the file part
        file = os.path.basename(self.data_file)
        self.txt_data_file.delete(0, END)
        self.txt_data_file.insert(0, file)

    def run_cmd(self):
        passfile = os.path.join(self.dir, self.pass_file.get())
        failfile = os.path.join(self.dir, self.fail_file.get())

        try:
            #wanna see its output with 2 few params?
            # subprocess.check_output([self.cmd_file, self.data_file, passfile])
            subprocess.check_output([self.cmd_file, self.data_file,passfile, failfile ])
        except subprocess.CalledProcessError as err:
            tkMessageBox.showerror("Problems...", "Utility returned:"+str(err.returncode) + " "+ err.output)
        else:
            tkMessageBox.showinfo("No worries", "SUCCESS")

def main():
    root = Tk()
    app = demoutil(root)
    root.mainloop()


if __name__ == "__main__":
    main()
