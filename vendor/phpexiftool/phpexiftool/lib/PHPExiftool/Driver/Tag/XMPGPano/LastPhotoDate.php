<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPGPano;

use PHPExiftool\Driver\AbstractTag;

class LastPhotoDate extends AbstractTag
{

    protected $Id = 'LastPhotoDate';

    protected $Name = 'LastPhotoDate';

    protected $FullName = 'XMP::GPano';

    protected $GroupName = 'XMP-GPano';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-GPano';

    protected $g2 = 'Image';

    protected $Type = 'date';

    protected $Writable = true;

    protected $Description = 'Last Photo Date';

    protected $local_g2 = 'Time';

}
