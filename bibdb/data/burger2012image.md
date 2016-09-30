
## Image denoising: Can plain Neural Networks compete with BM3D?

<bibentry>
@inproceedings{burger2012image,
  title={Image denoising: Can plain Neural Networks compete with BM3D?},
  author={Burger, Harold C and Schuler, Christian J and Harmeling, Stefan},
  booktitle={Computer Vision and Pattern Recognition (CVPR), 2012 IEEE Conference on},
  pages={2392--2399},
  year={2012},
  organization={IEEE}
}
</bibentry>


A study wether plain NN can beat BM3D. 
MLP network is given patches and it will produce noise free patches.
Best performance is given by a network _17.17-2047-2047-2047-2047-17.17_ . Patch size 17x17. Used Gray scale images. Activation functions tanh all the way. Used Berkeley segmentation + label me dataset. Tok about 1 month of training. Gives competitive results as compared to BM3D. Network adapted to many noise levels when trained on patches with different noise levels.

Some tricks used.
* Data normalization: pixel values are between 0-1 and then subtract 0.5 and then divide by 0.2=> mean 0 and variance 1.
* Weights initialization: Weights are sampled from a normal distribution with mean 0 and SD sqrt(N) where N no of neurons in the layer.
* each layer learning rate is divided by N
