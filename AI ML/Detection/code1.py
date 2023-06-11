# -*- coding: utf-8 -*-

import os
from groundingdino.util.inference import annotate, load_image, predict
from groundingdino.util.inference import load_model, load_image, predict, annotate

model = load_model("/home/pranshi/home/GroundingDINO/groundingdino/config/GroundingDINO_SwinT_OGC.py", "/home/pranshi/home/weight/groundingdino_swint_ogc.pth")

"""**TEST CODE**"""

import supervision as sv

img_path= "/home/pranshi/home/data/cig.jpeg"

prompt= " plastic, cigarette, glass, paper, cloth, shoe, leaf, shells, coconut"
BOX_TRESHOLD = 0.45
TEXT_TRESHOLD = 0.35

image_source, image = load_image(img_path)

boxes, logits, phrases = predict(
    model=model,
    image=image,
    caption=prompt,
    box_threshold=BOX_TRESHOLD,
    text_threshold=TEXT_TRESHOLD
)

annotated_frame = annotate(image_source=image_source, boxes=boxes, logits=logits,phrases=phrases)

# Commented out IPython magic to ensure Python compatibility.
# %matplotlib inline
sv.plot_image(annotated_frame, (16, 16))
