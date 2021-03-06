<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\DICOM;

use PHPExiftool\Driver\AbstractTag;

class PixelRepresentation extends AbstractTag
{

    protected $Id = '0028,0103';

    protected $Name = 'PixelRepresentation';

    protected $FullName = 'DICOM::Main';

    protected $GroupName = 'DICOM';

    protected $g0 = 'DICOM';

    protected $g1 = 'DICOM';

    protected $g2 = 'Image';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Pixel Representation';

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Unsigned',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'Signed',
        ),
    );

}
