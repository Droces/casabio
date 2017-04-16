<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Olympus;

use PHPExiftool\Driver\AbstractTag;

class ImageStabilization extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'ImageStabilization';

    protected $FullName = 'mixed';

    protected $GroupName = 'Olympus';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Olympus';

    protected $g2 = 'Camera';

    protected $Type = 'mixed';

    protected $Writable = false;

    protected $Description = 'Image Stabilization';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Off',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'On, Mode 1',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'On, Mode 2',
        ),
        3 => array(
            'Id' => 3,
            'Label' => 'On, Mode 3',
        ),
    );

}