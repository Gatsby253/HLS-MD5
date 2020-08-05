import os
import shutil
from distutils.dir_util import copy_tree

from setuptools import find_packages, setup

# project path in SD card & in github
board_notebooks_dir = os.environ['PYNQ_JUPYTER_NOTEBOOKS']
board_project_dir = os.path.join(board_notebooks_dir, 'MD5-HLS')
repo_jupyter_folder = 'Sourcecode/MD5_PYNQ/Jupyter'
repo_overlay_folder = 'ExecutableFiles/MD5_PYNQ'
repo_testdata_folder = 'HLS-MD5/Sourcecode/MD5_PYNQ/testdata'

# check whether board is supported
board = os.environ['BOARD']
if not board == 'Pynq-Z2':
    raise ValueError("Board {} is not supported.".format(board))
    
# check if the path already exists, delete if so
if os.path.exists(board_project_dir):
    shutil.rmtree(board_project_dir)
    
# copy overlays
src_ol_dir = os.path.join(repo_overlay_folder, 'MD5VIVADO.bit')
dst_ol_dir = os.path.join(board_project_dir, 'bitstream/MD5VIVADO.bit')
src_hwh_dir = os.path.join(repo_overlay_folder, 'MD5VIVADO.hwh')
dst_hwh_dir = os.path.join(board_project_dir, 'bitstream/MD5VIVADO.hwh')
src_tcl_dir = os.path.join(repo_overlay_folder, 'MD5VIVADO.tcl')
dst_tcl_dir = os.path.join(board_project_dir, 'bitstream/MD5VIVADO.tcl')
copy_tree(src_ol_dir, dst_ol_dir)
copy_tree(src_hwh_dir, dst_hwh_dir)
copy_tree(src_tcl_dir, dst_tcl_dir)

# copy notebook
src_nb_dir = os.path.join(repo_jupyter_folder, 'MD5.ipynb')
dst_nb_dir = os.path.join(board_project_dir, 'MD5.ipynb')
copy_tree(src_nb_dir, dst_nb_dir)

# copy testdata
src_td_dir = os.path.join(repo_testdata_folder)
dst_td_dir = os.path.join(board_project_dir, 'testdata')
copy_tree(src_td_dir, dst_td_dir)

setup(
    name="MD5-HLS",
    version='1.0',
    install_requires=[
        'pynq>=2.5',
    ],
    url='https://github.com/Gatsby253/HLS-MD5',
    license='Apache-2.0 License',
    packages=find_packages(),
    description="An implementation of MD5 algorithm on FPGA using Vivado HLS")